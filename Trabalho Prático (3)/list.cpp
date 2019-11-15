#include "list.h"

List::List(){
	this->begin = nullptr;
	this->end = nullptr;
	this->num_elements = 0;
}

~List::List(){
	Node *current;
	current = this->begin;
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

void List::push_back(Word x){
	if (!this->find_copy(x)) {
		if (!this->empty()){
			this->end->next = x;
			this->end = x;
			this->num_elements += 1;
		}
		else {
			this->begin = x;
			this->end = x;
			this->num_elements += 1;
		}	
	}
}

bool List::find_copy(Word x){
	Node *current;
	current = this->begin;
	while(current != nullptr){
		if (current->item->get_name() == x.get_name()){
			current->count++;
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
