#include "include/minheap.h"

//////////////////////////////
//					        				//
//  MINHEAP NODE FUNCTIONS  /////////////////////////////////
//					        				//
//////////////////////////////

MinHeapNode::MinHeapNode(){
	this->leaves = 0;
	this->freq = 0;
	this->left = this->right = nullptr;
}

void MinHeapNode::set_leaves(int var){
	this->leaves = var;
}

void MinHeapNode::set_freq(int var){
	this->freq = var;
}

void MinHeapNode::set_data(std::string var){
	this->data = var;
}

std::string MinHeapNode::get_data(){
	return this->data;
}

int MinHeapNode::get_freq(){
	return this->freq;
}

int MinHeapNode::get_leaves(){
	return this->leaves;
}

//////////////////////////
//					   					//
//  MINHEAP FUNCTIONS  	////////////////////////////////////////
//				       				//
//////////////////////////

MinHeap::MinHeap(Word *txt, int tam){
	this->create(tam);

	for (int i = 0; i < size; i++){
		MinHeapNode temp;
		this->array[i] = temp;
		this->array[i].set_data(txt[i].get_name());
		this->array[i].set_leaves(1);
		this->array[i].set_freq(txt[i].count);
	}

	this->size = tam;
	this->build();
}

void MinHeap::create(int tam){
	this->array = new MinHeapNode[tam];
	this->size = 0;
	this->capacity = tam;
}

void MinHeap::build(){
	int n = this->size - 1;

	//for (int i = (n - 1) / 2; i >= 0; --i)
	//	heapify(i);
}
