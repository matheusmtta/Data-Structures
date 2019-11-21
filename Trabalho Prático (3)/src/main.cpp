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
	
	//GET THE NUMBER OF NODES IN OUR TREE,
	//I.E THE NUMBER OF DIFFERENT WORDS IN
	//OUR INPUT
	for (int i = 0; i < 26; i++){
		tNodes += table.size(i);
	}

	//BUILD THE ARRAY THAT WILL BE USED AS
	//A BASIS FOR THE HEAP CONSTRUCTION
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

	MinHeapNode l, r, *top;

	while (!(myHeap->size == 1)){
		l = myHeap->extractMin();
		r = myHeap->extractMin();

		top = new MinHeapNode();

		top->set_data(l.get_data());
		top->set_freq(l.get_freq() + r.get_freq());
		top->set_leaves(l.get_leaves() + r.get_leaves());

		top->left = &l;
		top->right = &r;

		myHeap->insert(*top);
	}
	
	//MinHeapNode *root = myHeap->extractMin();

	//exit(0);

	while (std::cin >> cmd){
		std::cin >> palavra;
		//WORD FREQUENCY
		if (cmd == 'q'){
			int key = palavra[0] - 'a';
			int quant = table.wordFrequency(palavra, key);
			std::cout << quant << std::endl;
		}
		//WORD'S BINARY CODE
		else if (cmd == 'c') std::cout << "NOT READY YET" << std::endl;
	}

	delete[] arrNodes;

	return 0;
}
