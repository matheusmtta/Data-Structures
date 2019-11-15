#ifndef _LIST
#define _LIST

#include "text.h"
#include <string>

class Node{
	Word item;
	Word *next;
};

class List{
	Word *begin;
	Word *end;
	int num_elements;

	List();
	~List();
	bool empty();
	bool find_copy(Word);
	int size();
	void push_back(Word);
	void display();
}

#endif
