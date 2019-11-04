#include "includes/sort.h"
#include "includes/planet.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	int max_time, total_planets, name_size;
	std::cin >> max_time >> total_planets >> name_size;

	Planet list[total_planets];

	int tmp_time;
	std::string tmp_name;



	for (int i = 0; i < total_planets; i++){
		cin >> tmp_time >> tmp_name;
		list[i].set_time(tmp_time);
		list[i].set_name(tmp_name);
	}

	// std::cout << "Unsorted list:" << std::endl;
	// for (int i = 0; i < total_planets; i++){
	// 	std::cout << list[i].get_time() << " " << list[i].get_name() << std::endl;
	// }

	Sort_Merge(list, 0, total_planets-1);

	int k = 0, month = 1;
	int l = 0, r;
	while (k != total_planets){
		int sum = 0;
		while (sum < max_time && k != total_planets){
			sum += list[k].get_time();
			k++;
		}
		r = k;
		Radix(list, l, r-1, name_size);
		l = k;
		month++;
	}

	return 0;
}