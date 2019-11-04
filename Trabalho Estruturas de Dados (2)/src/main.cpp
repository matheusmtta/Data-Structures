#include "sort.h"
#include "planet.h"
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

	Sort_Merge(list, 0, total_planets-1);

	return 0;
}