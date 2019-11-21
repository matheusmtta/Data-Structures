#ifndef _TREE
#define _TREE

#include "text.h"
#include "list.h"
#include <string>

bool wgt(MinHeapNode a, MinHeapNode b);

class HuffMan {
	public:
		MinHeap *myHeap;
		MinHeapNode *root;
		
		HuffMan(Word *arr, int size);
		std::string get_code(std::string txt);
};

class MinHeapNode {
	public:
		unsigned leaves;
		unsigned freq = 0;
		std::string code;
		std::string data;
		MinHeapNode *left, *right;

		MinHeapNode(std::string, int, int);
}

class MinHeap {
	public:
		unsigned size;
		unsigned capacity;
		MinHeapNode array;

		MinHeap(Word *txt, int capacity);
		void heapify(int idx);
		void insert(MinHeapNode x);
		void swapMN(MinHeapNode *a, MinHeapNode*b);
		MinHeapNode extractMin();
}

#endif
