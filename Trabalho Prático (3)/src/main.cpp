#include "include/list.h"
#include "include/text.h"
#include "include/hash.h"
#include "include/minheap.h"
#include <iostream>
#include <string>

int main(){
	int n; 
	std::cin >> n;
	std::string palavra;

	int tNodes = 0;
	char cmd;

	Hash table;

	for (int i = 0; i < n; i++){
		std::cin >> palavra;
		int idx = palavra[0] - 'a';

		Word tmp;
		tmp.set_name(palavra);

		table.insert(tmp, idx);
	}
	
	for (int i = 0; i < 26; i++){
		tNodes += table.size(i);
	}

	Word *arrNodes;
	arrNodes = new Word[tNodes];

	int k = 0;

	for (int i = 0; i < 26; i++){
		for (int j = 0; j < table.size(i); j++){
			arrNodes[k] = table.get_element(i, j);
			k++;
		}
	}

	MinHeap *myHeap;
	myHeap = new MinHeap(arrNodes, tNodes);

	MinHeapNode *l, *r, *top;
	l = new MinHeapNode();
	r = new MinHeapNode();

	while (!(myHeap->size == 1)){
		l = (myHeap->extractMin());
		r = (myHeap->extractMin());

		top = new MinHeapNode();

		top->set_data(l->get_data());
		top->set_freq(l->get_freq() + r->get_freq());
		top->set_leaves(l->get_leaves() + r->get_leaves());

		top->left = l;
		top->right = r;

		myHeap->insert(top);
	}

	myHeap->set_codes(arrNodes, tNodes);

	while (std::cin >> cmd){
		std::cin >> palavra;
		if (cmd == 'q'){
			for (int i = 0; i < tNodes; i++){
				if (palavra == arrNodes[i].get_name())
					std::cout << arrNodes[i].count << std::endl;
			}
		}

		else if (cmd == 'c') {
			for (int i = 0; i < tNodes; i++){
				if (palavra == arrNodes[i].get_name())
					std::cout << arrNodes[i].get_code() << std::endl;
			}
		}
	}

	delete[] arrNodes;

	return 0;
}
