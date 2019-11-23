#include "include/minheap.h"
#include <string.h>

//////////////////////////////
//					        //
//  MINHEAP NODE FUNCTIONS  /////////////////////////////////////////////////
//					        //
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
//					   	//
//  MINHEAP FUNCTIONS  	/////////////////////////////////////////////////////
//				       	//
//////////////////////////

MinHeap::MinHeap(Word *txt, int tam){
	this->create(tam);
	for (int i = 0; i < tam; i++){
		this->array[i]->set_data(txt[i].get_name());
		this->array[i]->set_leaves(1);
		this->array[i]->set_freq(txt[i].count);
	}

	this->size = tam;

	for (int i = this->size - 1; i >= 0; i--){
		heapify(i);
	}
}

void MinHeap::create(int tam){
	this->array = (MinHeapNode**) malloc(tam * sizeof(MinHeapNode *));
	for (int i = 0; i < tam; i++)
		this->array[i] = (MinHeapNode*) malloc(sizeof(MinHeapNode));
	this->size = 0;
	this->capacity = tam;
}


bool wgt(MinHeapNode a, MinHeapNode b){
	if (a.get_freq() < b.get_freq()) return 1;
	else if (a.get_freq() > b.get_freq()) return 0;
	else {
		if (a.get_leaves() < b.get_leaves()) return 1;
		else if (a.get_leaves() > b.get_leaves()) return 0;
		else{
			return a.get_data().compare(b.get_data()) < 0 ? 1 : 0;
		}
	}
}

void MinHeap::swap_nodes(MinHeapNode **a, MinHeapNode **b){
	MinHeapNode *aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void MinHeap::heapify(int idx){
	int smallest = idx;
	int l = 2 * idx + 1;
	int r = 2 * idx + 2;

	if (l < this->size && wgt(*(this->array[l]), *(this->array[smallest])))
		smallest = l;

	if (r < this->size && wgt(*(this->array[r]), *(this->array[smallest])))
		smallest = r;

	if (smallest != idx){
		this->swap_nodes(&(this->array[smallest]), &(this->array[idx]));
		this->heapify(smallest);
	}
}	

MinHeapNode* MinHeap::extractMin(){
	MinHeapNode *temp = this->array[0];
	swap_nodes(&(this->array[0]), &(this->array[size - 1]));

	this->size--;
	this->heapify(0);

	return temp;
}

void MinHeap::insert(MinHeapNode *var){
	this->size++;
	int i = this->size - 1;

	while (i && wgt(*var, *(this->array[(i - 1)/ 2]))){
		this->array[i] = this->array[(i - 1) / 2];
		i = (i - 1) / 2; 
	}

	this->array[i] = var;
}

int MinHeap::get_size(){
	return this->size;
}

void MinHeap::set_codes(Word *txt, int tam){
	MinHeapNode root = *(this->array[0]);
	for (int i = 0; i < tam; i++){
		std::string name = txt[i].get_name();
		std::string tobuild;
		bool flag = false;
		create_code(root, &txt[i], tobuild, &flag);
	}
}

void create_code(MinHeapNode curr, Word *wanted, std::string str, bool *flag){
	if (!(curr.right) && !(curr.left)){
		if (wanted->get_name() == curr.get_data()){
			wanted->set_code(str);
			*flag = true;
		}
	}
	else{ 
		if (curr.left && !(*flag)){
			create_code(*(curr.left), wanted, str + "0", flag);
		}


		if (curr.right && !(*flag)){
			create_code(*(curr.right), wanted, str + "1", flag);
		}
	}
}