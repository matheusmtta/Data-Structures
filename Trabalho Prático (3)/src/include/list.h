#ifndef _LIST
#define _LIST

#include "text.h"
#include <string>

class Node{
	public:
		Word item;
		Node *next;
};

class List{
	public:
		Node *begin;
		Node *end;
		int num_elements;

	List();
	~List();
	bool empty();
	bool find_copy(std::string);
	int size();
	void push_back(Word);
	void display();
	int find(std::string);
};

#endif
