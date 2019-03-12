#include "../include/Dictionary.h"


Dictionary::Dictionary(int x) {
	max_size = x;
	offset_buff = new Node*[max_size];

	for (int i = 0; i < 256; i++) {
		hashTable[i] = 0;
	}

	head = 0;
	tail = 0;
	size = 0;
}

void Dictionary::push_back(char x) {
	if (size == 0) {
		offset_buff[head] = new Node;
		tail = head;
	}
	else {
		if (tail < (max_size - 1)) {
			offset_buff[++tail] = new Node;
		}
		else {
			tail = 0;
			offset_buff[tail] = new Node;
		}

	}
	offset_buff[tail]->element = (char)x;
	offset_buff[tail]->hash_next = 0;
	offset_buff[tail]->index = tail;

//Añade al hashtable
	add_to_table(offset_buff[tail]);
	size++;
}

//Remueve primer elemento en buffer
//y quita del hashtable.
void Dictionary::pop_front() {
	Node* holder = 0;
	if (head == max_size - 1) {
		holder = offset_buff[head];
		head = 0;
	}
	else {
		holder = offset_buff[head++];
	}
	//Quita del hashtable
	remove_from_table(holder);
	delete(holder);
	size--;
}

//Obtiene del offset_buff
//Output:
//	char
char Dictionary::back() {
	return offset_buff[tail]->element;
}

//regresa el proximo node al buffer
Node* Dictionary::next(Node* node) {
	int node_index = node->index;
	if (node_index == tail) {
		return 0;
	}

	if (node_index < tail && node_index >= head) {
		return offset_buff[node_index + 1];
	}
	else if (node_index >= head) {
		if (node_index == max_size - 1) {
			return offset_buff[0];
		}
		else {
			return offset_buff[node_index + 1];
		}
	}
	else if (node_index < tail && node_index < head) {
		return offset_buff[node_index + 1];
	}
}


Node* Dictionary::get_Node(char x) {
	int key = (unsigned int)x & 0xFF;
	return hashTable[key];
}


int Dictionary::get_offset(Node* x) {
	int count = -1;
	if (x->index > tail) {
		count = (max_size - (x->index)) + tail;
	}
	else {
		count = tail - (x->index);
	}
	return count + 1;
}


int Dictionary::get_size() {
	return size;
}


void Dictionary::add_to_table(Node* x) {
	int key = ((unsigned int)(x->element)) & 0xFF;
	if (hashTable[key] == 0) {
		hashTable[key] = x;
		x->hash_prev = 0;
	}
	else {
		Node* current_node = hashTable[key];
		while (current_node->hash_next != 0) {
			current_node = current_node->hash_next;
		}
		current_node->hash_next = x;
		x->hash_prev = current_node;
	}

}


void Dictionary::remove_from_table(Node* x) {
	int key = ((unsigned int)(x->element)) & 0xFF;
	hashTable[key] = x->hash_next;
	if (x->hash_next != 0) {
		x->hash_next->hash_prev = 0;
	}
	else {
		hashTable[key] = 0;
	}
}
