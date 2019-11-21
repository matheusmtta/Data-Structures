#include "include/tree.h"

HuffMan::HuffMan(Word *arr, int size){
	this->myHeap = new MinHeap(Word, size);

	while (myHeap.size() != 1){
		this->left = myHeap.extractMin();
		this->right = myHeap.extractMin();

		this->top = MinHeapNode(left.data, left->freq + right->freq, left->leaves + right->leaves);
		this->top->left = left;
		this->top->right = right;

		myHeap.insert(top);
	}

	this->root = myHeap.extractMin();
}

MinHeapNode::MinHeapNode(std::string name, int quant, int lfs){
	this->data = name;
	this->leaves = lfs;
	this->freq = quant;
	this->left = this->right = nullptr;
}

MinHeap::MinHeap(Word *txt, int tam){
	this->array = new MinHeapNode[tam];
	this->capacity = tam;

	for (int i = 0; i < tam; ++i){
		MinHeapNode temp = MinHeapNode(array[i].get_name(), array[i].count, 1);
		this->array[i] = temp;
	}

	this->size = tam;

	int n = this->size - 1;

	for (int i = (n - 1)/2; i >= 0; --i)
		this->heapify(i);
}

bool wgt(MinHeapNode a, MinHeapNode b){
	//CASE 1. COMPARE BY THE WORD FREQUENCY
	if (a.freq < b.freq) 
		return 1; 
	else if (a.freq > b.freq) 
		return 0;
	else { //CASE 2. WE NEED TO COMPARE BY ITS SUBTREES NUMBER OS LEAVES
		if (a.leaves < b.leaves) 
			return 1;
		else if (a.leaves > b.leaves) 
			return 0;
		else { //CASE 3. WE NEED TO COMPARE BY ITS MINIMAL STRINGS
			int maxi = a.data.length();

			if (maxi < b.data.length()) 
				maxi = b.data.length();

			for (int i = 0; i < maxi; i++){
				int x = a[i] - 'a', y = b[i] - 'a';
				if (x < y) return 1;
				else if (x > y) return 0;
			}
		}
	}
}

void MinHeap::heapify(int idx){
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < this->size && wgt(arr[left], arr[smallest]));
		smallest = left;

	if (right < this->size && wgt(arr[right], arr[smallest]));
		smallest = right;

	if (smallest != idx) {
		this->swapMP(arr[idx], arr[smallest]);
		this->heapify(smallest);
	}
}

void MinHeap::swapMN(MinHeapNode *a, MinHeapNode *b){
	MinHeapNode *t = a;
	a = b;
	b = t;
}

MinHeapNode MinHeap::extractMin(){
	MinHeapNode *temp = this->array[0];
	this->array[0] = this->array[this->size-1];

	this->size--;

	this->heapify(0);

	return temp;
}

void MinHeap::insert(MinHeapNode x){
	this->size++;
	int i = this->size - 1;

	while (i && wgt(x, this->arr[(i - 1) / 2])){
		this->array[i] = this->array[(i - 1)/ 2];
		i = (i - 1) / 2;
	}

	this->array[i] = x;
}
