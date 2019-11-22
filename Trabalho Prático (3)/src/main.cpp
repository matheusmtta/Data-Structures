#include "include/list.h"
#include "include/text.h"
#include "include/hash.h"
#include "include/minheap.h"
#include <iostream>
#include <string>

void dfs (MinHeapNode *aux){
	std::cout << '|' << aux->get_data() << '|' << std::endl;
	if (aux->left != nullptr) dfs(aux->left);
	if (aux->right != nullptr) dfs(aux->right);
}

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

	MinHeapNode *l, *r, *top;
	l = new MinHeapNode();
	r = new MinHeapNode();

	// std::cout << "-----------------" << std::endl;

	while (!(myHeap->size == 1)){
		l = (myHeap->extractMin());
		r = (myHeap->extractMin());

		top = new MinHeapNode();

		//std::string aux = l->get_data();

		// std::cout << "freq: " << l->get_freq() + r->get_freq() << std::endl;
		// std::cout << "n leaves: " << l->get_leaves() + r->get_leaves() << std::endl;
		// std::cout << "name: " << l->get_data() << std::endl;
		// std::cout << "-----------------" << std::endl;
		top->set_data(l->get_data());
		top->set_freq(l->get_freq() + r->get_freq());
		top->set_leaves(l->get_leaves() + r->get_leaves());

		top->left = l;
		top->right = r;

		myHeap->insert(top);
	}

	//MinHeapNode *aux;
	//aux = new MinHeapNode();

	//aux = myHeap->extractMin();

	//dfs(aux);

	myHeap->set_codes(arrNodes, tNodes);

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
		else if (cmd == 'c') {
			for (int i = 0; i < tNodes; i++){
				if (palavra == arrNodes[i].get_name())
					std::cout << arrNodes[i].get_code() << std::endl;
			}
		}//std::cout << "NOT READY YET" << std::endl;
	}

	delete[] arrNodes;

	return 0;
}
