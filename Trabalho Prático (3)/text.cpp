#include "text.h"



void Word::set_count(int x){
	this->count = x;
}

void Word::set_code(std::string str){
	this->code = str;
}

void Word::set_name(std::string str){
	this->name = str;
}

int Word::get_count(){
	return this->count;
}

std::string Word::get_name(){
	return this->name;
}

std::string Word::get_code(){
	return this->code;
}

void Word::display(){
	std::cout << "Palavra: " << this->name << std::endl;
	std::cout << "Codigo: " << this->code << std::endl;
	std::cout << "Count: " << this->count << std::endl;
}
