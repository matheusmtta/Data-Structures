#ifndef _HEAP
#define _HEAP

#include "text.h"
#include "list.h"
#include <string>

class MinHeapNode {
	private:
		unsigned int leaves;
		unsigned int freq;
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
 		unsigned int size;
 		unsigned int capacity;
 		MinHeapNode *array;
 		MinHeap(Word*, int);
 		void create(int);
 		void build();
// 		void heapify(int);
// 		void insert(MinHeapNode);
// 		void swap_nodes(MinHeapNode*, MinHeapNode*);
// 		int get_size();
 	};

#endif