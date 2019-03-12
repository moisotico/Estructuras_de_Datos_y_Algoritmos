#ifndef __DICT__
#define __DICT__

class Node {
public:
	char element;
	int index;
	Node* hash_next;
	Node* hash_prev;
};

class Dictionary {
public:

	Dictionary(int);

	void push_back(char);
	void pop_front();
	char back();
	Node* next(Node*);
	Node* get_Node(char);
	int get_offset(Node*);
	int get_size();

private:

	int head;
	int tail;
	int size;
	int max_size;

	Node** offset_buff;

	Node* hashTable[256];

	void add_to_table(Node*);
	void remove_from_table(Node*);
};

#endif
