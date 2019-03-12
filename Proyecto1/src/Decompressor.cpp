//para leer y escribir en archivos.
#include <fstream>
#include <iostream>
#include "../include/Decompressor.h"

using namespace std;

//Constructor
Decompressor::Decompressor(){
    //Vslores default
    window_offset_bits = def_window_offset_bits;
    match_len_bits = def_match_len_bits;
    str_len_bits = def_str_len_bits;

    window_size = 1 << window_offset_bits;
    //buffer de preanalisis
    lookahead_buff = (1 << match_len_bits) - 1;

    max_substring_len = (1 << match_len_bits);
    longest_str_len = (1 << str_len_bits) - 1;

    decomp_filesize = 0;
    comp_filesize = 0;
}


int Decompressor::getCompSize(){
	return comp_filesize;
}

int Decompressor::DecompFile(string archivo) {
    ifstream file_input(archivo.c_str(), ifstream::binary);
    if (!file_input.is_open()) {
        cerr << "Archivo no encontrado." << endl;
        return -1;
    }

    istream* input = &file_input;
    char current_char[1];

    unsigned int bit_package_buffer = 0;
    int used_bits = 0;

    //Obtener parametros
    if(!input->read(current_char, 1)){
        cerr << "Compresión Incorrecta" << endl;
        return -1;
    }
    window_offset_bits = (int)current_char[0];
    if(window_offset_bits > 14 || window_offset_bits < 9){
        cerr << "# de bits de offset de la ventana fuera de límites" << endl;
        return -1;
    }
    setOffsetBits(window_offset_bits);

    if(!input->read(current_char, 1)){
        cerr << "Compresión Incorrecta" << endl;
        return -1;
    }
    match_len_bits = (int)current_char[0];
    if(match_len_bits > 4 || match_len_bits < 3){
        cerr << "número de bits coincidentes fuera de límites" << endl;
        return -1;
    }
    setMatchLengthBits(match_len_bits);

    if(!input->read(current_char, 1)){
        cerr << "Compresión Incorrecta" << endl;
        return -1;
    }
    str_len_bits = (int)current_char[0];
    if(str_len_bits > 5 || str_len_bits < 1){
        cerr << "número de bits de longitud del string fuera de los límites" << endl;
        return -1;
    }
    setStringLengthBits(str_len_bits);

    comp_filesize += 3;


    cerr << "Tamaño de ventana: " << window_size << endl;
    cerr << "Tamaño del buffer de preanálisis: " << lookahead_buff << endl;
    cerr << "Tamaño del mayor String codificado: " << longest_str_len << endl;

    bool finished = false;
    while (finished == false) {
        while ((32 - used_bits)  >= 8) {
            if (input->read(current_char, 1)) {
                comp_filesize++;
                bit_package_buffer |= ((current_char[0] & 0xFF) << (32 - used_bits - 8));
                used_bits += 8;
            }
            else {
                break;
            }
        }

        //lee L bits
        int len = (bit_package_buffer >> (32 - match_len_bits));
        if (len != 0) {
            len++;
        }
        //Quita L bits del buffer.
        bit_package_buffer = bit_package_buffer << match_len_bits;
        used_bits -= match_len_bits;

        if (len >= 2) {
            //lee N bits del buffer.
            int offset = (bit_package_buffer >> (32 - window_offset_bits));

            //Quita N bits del buffer.
            bit_package_buffer = bit_package_buffer << window_offset_bits;
            used_bits -= window_offset_bits;

            int current_window = window.size();

            for (int i = 0; i < len; i++) {
                if(((current_window - offset) + i) > window.size() || ((current_window) + i) < 0){
                    cerr << "Compresión Incorrecta" << endl;
                    return -1;
                }

                cout << window[(current_window - offset) + i];
                decomp_filesize++;
                if ((window.size() + 1) > window_size) {
                    //quita extras
                    window.pop_front();
                    current_window--;
                }
                window.push_back(window[(current_window - offset) + i]);
            }

            //Refill buffer.
            while ((32 - used_bits) >= 8) {
                if (input->read(current_char, 1)) {
                    comp_filesize++;
                    bit_package_buffer |= ((current_char[0] & 0xFF) << (32 - used_bits - 8));
                    used_bits += 8;
                }
                else {
                    break;
                }
            }

        }
        else if(len == 0) {
            //Lee S bits del buffer.
            int strlen = (bit_package_buffer >> (32 - str_len_bits));
            //Quita S bits del buffer.
            bit_package_buffer = bit_package_buffer << str_len_bits;
            used_bits -= str_len_bits;

            //Termina de descomprimir el archivo
            if (strlen == 0) {
                finished = true;
            }
            else if (strlen > 0) {
                for (int i = 0; i < strlen; i++) {
                    //Llena el bit_package_buffer.
                    while ((32 - used_bits) > 8) {
                        if (input->read(current_char, 1)) {
                            comp_filesize++;
                            bit_package_buffer |= ((current_char[0] & 0xFF) << (32 - used_bits - 8));
                            used_bits += 8;
                        }
                        else {
                            break;
                        }
                    }
                    //Lee un char del buffer.
                    char literal_char = bit_package_buffer >> (32 - 8);
                    //RQuita un char del buffer
                    bit_package_buffer = bit_package_buffer << 8;
                    used_bits -= 8;

                    //Print char
                    cout << literal_char;
                    decomp_filesize++;
                    //char a window
                    if ((window.size() + 1) > window_size) {
                        //Sin extras
                        window.pop_front();
                    }
                    window.push_back(literal_char);
                }
            }
        }
        else {
            cerr << "Compresión Incorrecta" << endl;
            return -1;
        }
    }
    return decomp_filesize;
}
void Decompressor::setOffsetBits(int n) {
	window_offset_bits = n;
	window_size = 1 << window_offset_bits;
}


void Decompressor::setMatchLengthBits(int l) {
	match_len_bits = l;
	max_substring_len= (1 << match_len_bits);
	lookahead_buff = (1 << match_len_bits) - 1;
}

//Numero de  bits para codificar string.
//cambia longitud máxima de mayor string codificado.
//@param int s: número de bits para codificar lingitud de string.
void Decompressor::setStringLengthBits(int s) {
	str_len_bits = s;
	longest_str_len = (1 << str_len_bits) - 1;
}
