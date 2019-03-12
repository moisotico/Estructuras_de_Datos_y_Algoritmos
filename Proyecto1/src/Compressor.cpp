#include <iostream>
#include <fstream>
#include "../include/Compressor.h"

using namespace std;


Compressor::Compressor() {
	window_offset_bits = def_window_offset_bits;
	match_len_bits = def_match_len_bits;
	str_len_bits = def_str_len_bits;

	bit_buff = 0;
	used_bits = 0;

	comp_filesize = 0;

	//Se juntan los parámetros en 3 bytes
	params[2] = (char)(window_offset_bits & 0xFF);
	params[1] = (char)(match_len_bits & 0xFF);
	params[0] = (char)(str_len_bits & 0xFF);

	window_size = 1 << window_offset_bits;
	lookahead_buff = (1 << match_len_bits) - 1;
	max_substring_len = (1 << match_len_bits);
	longest_str_len = (1 << str_len_bits) - 1;

}

int Compressor::CompressFile(string fileName) {

    cerr << "Tamaño de ventana: " << window_size << endl;
    cerr << "Tamaño del buffer de preanálisis: " << lookahead_buff << endl;
    cerr << "Tamaño del mayor String codificado: " << longest_str_len << endl;

	offset_buff = new Dictionary(window_size - lookahead_buff);
	char current_char[1];

	ifstream input(fileName.c_str(), ifstream::binary);
	if (!input.is_open()) {
		cerr << "File not found." << endl;
		return -1;
	}

	//Inicializamos el buffer de preanalisis
	for (int i = 0; i < lookahead_buff; i++) {
		if (input.read(current_char, 1)) {
			preview_buff.push_back(current_char[0]);
		}
		else {
			break;
		}
	}

	//Output de los parametros en forma de bytes.
	for (int i = 2; i >= 0; i--) {
		std::cout << params[i];
		comp_filesize++;
	}

	bool previous_triple = false;
	int triple_count = 0;
	char* literal_string = new char[longest_str_len];

	while (!preview_buff.empty()) {
		pair<int, int> token = longest_match();
		if (token.first == 0) {
			if (previous_triple == false ||longest_str_len <= triple_count) {
				if (triple_count > 0) {
					//Agrega token al bit buffer.
					make_space(match_len_bits);
					used_bits += match_len_bits;

					//Agrega strlen al bit buffer.
					make_space(str_len_bits);
					bit_buff |= ((triple_count & 0xFF) << (32 - used_bits - str_len_bits));
					used_bits += str_len_bits;

					//Agrega caracteres leidos al bit buffer.
					for (int i = 0; i < triple_count; i++) {
						make_space(8);
						bit_buff |= ((literal_string[i] & 0xFF) << (32 - used_bits - 8));
						used_bits += 8;
					}
				}
				triple_count = 0;
				literal_string[triple_count++] = offset_buff->back();
			}
			else{
				literal_string[triple_count++] = offset_buff->back();
			}

			previous_triple = true;
		}
		else {
			if (previous_triple == true) {

				make_space(match_len_bits);
				used_bits += match_len_bits;

				// strlen al bit buffer.
				make_space(str_len_bits);
				bit_buff |= ((triple_count & 0xFF) << (32 - used_bits - str_len_bits));
				used_bits += str_len_bits;

				//caracteres leidos al bit buffer.
				for (int i = 0; i < triple_count; i++) {
					make_space(8);
					bit_buff |= ((literal_string[i] & 0xFF) << (32 - used_bits - 8));
					used_bits += 8;
				}
				previous_triple = false;
				triple_count = 0;
			}

			//Longitud match_len_bits al bit buffer.
			make_space(match_len_bits);
			bit_buff |= (((token.first - 1) & 0xFF) << (32 - used_bits - match_len_bits));
			used_bits += match_len_bits;

			//offset al bit buffer.
			make_space(window_offset_bits);
			bit_buff |= ((token.second & 0xFFFF) << (32 - used_bits - window_offset_bits));
			used_bits += window_offset_bits;
		}

		//Vacía los bytes usados de used_bits
		if ((used_bits / 8) > 0) {
			for (int i = 0; i < (used_bits / 8); i++) {
				cout << (char)((bit_buff >> 24) & 0xFFFF);
				comp_filesize++;
				bit_buff = bit_buff << 8;
				used_bits -= 8;
			}
		}

		//Rellena el preview buff.
		if (token.first == 0) {
			if (input.read(current_char , 1)) {
				preview_buff.push_back(current_char[0]);
			}
		}
		else {
			for (int i = 0; i < token.first; i++) {
				if (input.read(current_char, 1)) {
					preview_buff.push_back(current_char[0]);
				}
				else {
					break;
				}
			}
		}
	}

	//Vacia el string buffer.
	if (previous_triple == true) {
		//Añade token al bit buffer.
		make_space(match_len_bits);
		used_bits += match_len_bits;

		//Agrega strlen al bit buffer.
		make_space(str_len_bits);
		bit_buff |= ((triple_count & 0xFF) << (32 - used_bits - str_len_bits));
		used_bits += str_len_bits;

		//Agrega caracteres al bit buffer.
		for (int i = 0; i < triple_count; i++) {
			make_space(8);
			bit_buff |= ((literal_string[i] & 0xFF) << (32 - used_bits - 8));
			used_bits += 8;
		}
		previous_triple = false;
		triple_count = 0;
	}

	make_space(match_len_bits);
	used_bits += match_len_bits;

	make_space(str_len_bits);
	used_bits += str_len_bits;

	if (used_bits > 0) {
		int remainder = (used_bits + 8 - 1) / 8;
		for (int i = 0; i < remainder; i++) {
			cout << (char)((bit_buff >> 24) & 0xFFFF);
			comp_filesize++;
			bit_buff = bit_buff << 8;
			used_bits -= 8;
		}
	}
	return comp_filesize;
}


void Compressor::setOffsetBits(int n) {
	window_offset_bits = n;
	window_size = 1 << window_offset_bits;
	params[2] = (char)(window_offset_bits & 0xFF);
}


void Compressor::setMatchLenBits(int l) {
	match_len_bits = l;
	max_substring_len = (1 << match_len_bits);
	lookahead_buff = (1 << match_len_bits) - 1;
	params[1] = (char)(match_len_bits & 0xFF);
}

void Compressor::setStringLenBits(int s) {
	str_len_bits = s;
	longest_str_len = (1 << str_len_bits) - 1;
	params[0] = (char)(str_len_bits & 0xFF);
}

pair<int, int> Compressor::longest_match() {
	int best_match_length = 0;
	int best_match_offset = 1;
	int current_offset = 0;

	Node* current_node = offset_buff->get_Node(preview_buff[0]);

	if (current_node != 0) {
		//último nodo en el hastable bucket
		while (current_node->hash_next != 0) {
			current_node = current_node->hash_next;
		}
		//Itera a través del hashtable bucket
		while (current_node != 0) {
			Node* current_offset_node = current_node;
			int current_length = 0;
			int overflow = 0;

			char offset_char = current_offset_node->element;
			int current_offset = offset_buff->get_offset(current_offset_node);
			char lookahead_char = preview_buff.front();

			while (lookahead_char == offset_char && current_length < max_substring_len) {
				current_length++;

				//próximo byte del offset_buff.
				if (offset_buff->next(current_offset_node) != 0) {
					current_offset_node = offset_buff->next(current_offset_node);
					offset_char = current_offset_node->element;
				}
				else {
                    
					offset_char = preview_buff[overflow++];
				}
				//Próximo byte desde el buff de preanalsis.
				if (current_length < preview_buff.size()) {
					lookahead_char = preview_buff[current_length];
				}
				else {
					break;
				}
			}
			//Remplaza cuando se encuentra un resultado más acertado
			if (current_length > best_match_length) {
				best_match_length = current_length;
				best_match_offset = current_offset;
				if (best_match_length == max_substring_len) {
					break;
				}
			}
			current_node = current_node->hash_prev;
		}
	}

	//Mueve chars del preanálisis al offset
	if (best_match_length > 1) {
		int offset_buff_size_after = best_match_length + offset_buff->get_size();
		int max_offset_size = window_size - lookahead_buff;
		int amount_overflow = offset_buff_size_after - max_offset_size;
		if (amount_overflow > 0) {
			for (int i = 0; i < amount_overflow; i++) {
				offset_buff->pop_front();
			}
		}

		for (int i = 0; i < best_match_length; i++) {
			offset_buff->push_back(preview_buff.front());
			preview_buff.pop_front();
		}
	}
	else {
		int max_offset_size = window_size - lookahead_buff;
		if (offset_buff->get_size() == max_offset_size) {
			offset_buff->pop_front();
		}
		offset_buff->push_back(preview_buff.front());
		preview_buff.pop_front();
		best_match_length = 0;
		best_match_offset = 1;
	}

	return pair<int, int>(best_match_length, best_match_offset);
}


void Compressor::make_space(int bits) {
	if (used_bits + bits > 32) {
		cout << (char)((bit_buff >> 24) & 0xFFFF);
		cout << (char)((bit_buff >> 16) & 0xFFFF);
		comp_filesize += 2;
		bit_buff = bit_buff << 16;
		used_bits -= 16;
	}
}
