#include "include/hash.h"

Hash::Hash(){
	//ALPHABET SIZE
	this->table = new List[26];
}

void Hash::insert(Word x, int key){
	this->table[key].push_back(x);
}

void Hash::displayHash(int key){
 	table[key].display();
}

int Hash::wordFrequency(std::string x, int key){
	return table[key].find(x);
}