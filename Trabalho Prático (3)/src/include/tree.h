#ifndef _TREE
#define _TREE

#include "text.h"
#include "list.h"
#include <string>

class MinHeapNode {
	public:
		std::string data;
		unsigned freq = 0;
		MinHeapNode *left, *right;

		MinHeapNode(Word txt);
}

class MinHeap {
	public:
		unsigned size;
		unsigned capacity;
		MinHeapNode array;

		MinHeap(Word *txt, int capacity);
		void heapify(int idx);
		void insert(MinHeapNode x);
		void *swapMN(MinHeapNode *a, MinHeapNode*b);
		int isSizeOne();
		MinHeapNode extractMin();
}

#endif
