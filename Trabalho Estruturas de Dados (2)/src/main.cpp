#include "includes/sort.h"
#include "includes/planet.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	int max_time, total_planets, name_size;
	std::cin >> max_time >> total_planets >> name_size;
	Planet *list_planets =  new Planet[total_planets];

	int tmp_time;
	std::string tmp_name;

	for (int i = 0; i < total_planets; i++){
		cin >> tmp_time >> tmp_name;
		list_planets[i].set_time(tmp_time);
		list_planets[i].set_name(tmp_name);
	}

	Sort_Merge(list_planets, 0, total_planets-1);

	int k = 0, month = 1;
	int l = 0, r;

	while (k != total_planets){
		int sum = 0;
		while (sum <= max_time && k != total_planets){
			if (sum + list_planets[k].get_time() > max_time) break;
			sum += list_planets[k].get_time();
			k++;
		}
		r = k;
		Radix(list_planets, l, r, name_size);
		for (int i = l; i < k; i++){
			std::cout << month << " " << list_planets[i].get_name() << " " << list_planets[i].get_time() << std::endl;
		}
		l = k;
		month++;

	}

	delete[] list_planets;

	return 0;
}