#ifndef _HASH
#define _HASH

#include <iostream>
#include <string>
#include "text.h"
#include "list.h"

class Hash{
	private:
		List *table;
	public:
		Hash();
		void insert(Word, int);
		void displayHash(int);
		int wordFrequency(std::string, int);
		int size(int);
		Word get_element(int, int);
};

#endif