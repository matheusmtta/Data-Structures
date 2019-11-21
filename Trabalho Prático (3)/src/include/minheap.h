#ifndef _HEAP
#define _HEAP

#include "text.h"
#include "list.h"
#include <string>

class MinHeapNode {
	private:
		int leaves;
		int freq;
		std::string data;
	public:
		MinHeapNode *left, *right;

		MinHeapNode();
		void set_leaves(int);
		void set_data(std::string);
		void set_freq(int);
		int get_leaves();
		int get_freq();
		std::string get_data();
};

class MinHeap {
 	public:
 		int size;
 		int capacity;
 		MinHeap(Word*, int);
 		MinHeapNode *array;
		MinHeapNode extractMin();
 		void create(int);
 		void build();
 		void heapify(int);
	 	void swap_nodes(MinHeapNode*, MinHeapNode*);
 		void insert(MinHeapNode);
 		int get_size();
 	};

#endif