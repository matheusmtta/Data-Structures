#include "include/tree.h"

MinHeapNode::MinHeapNode(Word txt){
	this->data = txt.get_name();
	this->freq = txt.count;
	this->left = nullptr;
}

MinHeap::MinHeap(int capacity, Word *txt){
	this->capacity = capacity;
	this->size = 0;
	this->array = new MinHeapNode[capacity];

	for (int i = 0; i < capacity; ++i){
		MinHeapNode aux(Word);
		this->array[i] = insert(aux);
	}

	this->size = capacity;

	int n = this->size - 1;
	int i;

	for (i = (n-1)/2; i >= 0; --i)
		this->heapify(i);
}

MinHeap::~MinHeap(){
	delete[] this->array;
}

void MinHeap::heapify(int idx){
 	int smallest = idx;
 	int left = 2 * idx + 1;
 	int right = 2 * idx + 2;

 	if (left < this->size && this->array[left]->freq < this->array[smallest]->freq)
 		smallest = left;

 	if (right < this->size && this->array[right]->freq < this->array[smallest]->freq)
 		smallest = right;

 	if (smallest != idx){
 		swap(this->array[smallest], this->array[idx]);
 		heapify(smallest);
 	}
}		

void MinHeap::swap(MinHeapNode *a, MinHeapNode *b){
	MinHeapNode *t = a;
	a = b;
	b = t;
}

void insert(MinHeapNode x){
	this->++size;
	int i = this->size-1;

	while (i && x.freq < this->array[(i -1)/2].freq){
		this->array[i] = this->array[(i-1)/2];
		i = (i - 1)/2;
	}

	this->array[i] = x;
}