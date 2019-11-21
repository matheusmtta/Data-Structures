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

	for (int i = (n - 1) / 2; i >= 0; --i)
		heapify(i);
}

bool wgt(MinHeapNode a, MinHeapNode b){
	if (a.get_freq() < b.get_freq()) return 1;
	else if (a.get_freq() > b.get_freq()) return 0;
	else {
		if (a.get_leaves() < b.get_leaves()) return 1;
		else if (a.get_leaves() > b.get_leaves()) return 0;
		else{
			std::string x = a.get_data(), y = b.get_data();
			int mini = x.length();

			if (y.length() < mini) mini = y.length();

			for (int i = 0; i < mini; i++){
				if (x[i] < y[i]) return 1;
				else if (x[i] > y[i]) return 0;
			}

			if (x.length() < y.length()) return 1;
			else return 0;
		}
	}
}

void MinHeap::swap_nodes(MinHeapNode *a, MinHeapNode *b){
	MinHeapNode *aux;
	aux = a;
	a = b;
	b = aux;
}

void MinHeap::heapify(int idx){
	int smallest = idx;
	int l = 2 * idx + 1;
	int r = 2 * idx + 2;

	if (l < this->size && wgt(this->array[l], this->array[smallest]))
		smallest = l;

	if (r < this->size && wgt(this->array[r], this->array[smallest]))
		smallest = r;

	if (smallest != idx){
		this->swap_nodes(&(this->array[smallest]), &(this->array[idx]));
		this->heapify(smallest);
	}
}	

MinHeapNode MinHeap::extractMin(){
	MinHeapNode temp = this->array[0];
	this->array[0] = this->array[this->size - 1];

	this->size--;
	this->heapify(0);

	return temp;
}

void MinHeap::insert(MinHeapNode var){
	this->size++;
	int i = this->size - 1;

	while (i && wgt(var, this->array[(i - 1)/ 2])){
		this->array[i] = this->array[(i - 1) / 2];
		i = (i - 1) / 2; 
	}

	this->array[i] = var;
}

int MinHeap::get_size(){
	return this->size;
}