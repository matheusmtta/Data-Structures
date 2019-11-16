#include "include/list.h"
#include "include/text.h"
#include "include/hash.h"
#include <iostream>
#include <string>

int main(){
	int n; 
	std::cin >> n;
	std::string palavra;
	char cmd;

	Hash table;

	for (int i = 0; i < n; i++){
		std::cin >> palavra;
		int idx = palavra[0] - 'a';

		Word tmp;
		tmp.set_name(palavra);

		table.insert(tmp, idx);
	}
	//table.displayHash(0);

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

	return 0;
}
