#include "include/list.h"

List::List(){
	this->begin = nullptr;
	this->end = nullptr;
	this->num_elements = 0;
}

List::~List(){
	Node *current = this->begin;
	while(current != nullptr){
		this->begin = this->begin->next;
		delete (current);
		current = this->begin;
		this->num_elements -= 1;
	}
}

bool List::empty(){
	if (num_elements) return false;
	return true;
}

int List::size(){
	return this->num_elements;
}

void List::push_back(Word aux){
	if (find_copy(aux.get_name())) {
		return;
	}
	else{
		Node *node = new Node;
		node->item = aux;
		node->item.count++;
		node->next = nullptr;
		if (num_elements == 0){
			this->begin = node;
    	this->end = node;
		}
		else {
			this->end->next = node;
    	this->end = node;
		}
		num_elements += 1;
	}
}

bool List::find_copy(std::string aux){
	Node *current;
	current = this->begin;
	while(current != nullptr){
		if (current->item.get_name() == aux){
			current->item.count++;
			return true;
		}
		current = current->next;
	}
	return false;
}

void List::display(){
	Node *current;
	current = this->begin;
	if (this->empty()) std::cout << "vazio" << std::endl;
	while (current != nullptr){
		current->item.display();
		current = current->next;
		std::cout << "-----------" << std::endl;
	}
}

int List::find(std::string palavra){
	Node *current;
	current = this->begin;
	while (current != nullptr){
		if (current->item.get_name() == palavra){ 
			return current->item.count;
		}
		current = current->next;
	}
	return 0;
}
