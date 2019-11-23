#include "include/hash.h"

Hash::Hash(){
	this->table = new List[26];
}

void Hash::insert(Word x, int key){
	this->table[key].push_back(x);
}

void Hash::displayHash(int key){
 	this->table[key].display();
}

int Hash::wordFrequency(std::string x, int key){
	return this->table[key].find(x);
}

int Hash::size(int key){
	return this->table[key].size();
}

Word Hash::get_element(int key, int position){
	return this->table[key].find(position);
}