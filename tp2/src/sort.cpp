#include "includes/planet.h"
#include "includes/sort.h"
#include <string>

void Merge(Planet *arr, int left, int middle, int right){
	int size1 = middle-left+1;
	int size2 = right-middle;

	Planet L_arr[size1];
	Planet R_arr[size2];

	for (int i = 0; i < size1; i++){
		L_arr[i].set_name(arr[left+i].get_name());
		L_arr[i].set_time(arr[left+i].get_time());
	}
	for (int i = 0; i < size2; i++){
		R_arr[i].set_name(arr[middle+1+i].get_name());
		R_arr[i].set_time(arr[middle+1+i].get_time());
	}

	int i=0, j=0, k=left;
	while (i < size1 && j < size2){
		if (L_arr[i].get_time() <= R_arr[j].get_time()){
			arr[k].set_time(L_arr[i].get_time());
			arr[k].set_name(L_arr[i].get_name());
			i++; 
		}
		else {
			arr[k].set_time(R_arr[j].get_time());
			arr[k].set_name(R_arr[j].get_name());
			j++; 
		}
		k++;
	}

	while (i < size1){
		arr[k].set_time(L_arr[i].get_time());
		arr[k].set_name(L_arr[i].get_name());
		i++;
		k++;
	}

	while (j < size2){
		arr[k].set_time(R_arr[j].get_time());
		arr[k].set_name(R_arr[j].get_name());
		j++;
		k++;
	}
}

void Sort_Merge(Planet *arr, int left, int right){
	if (left < right){
		int middle = (left+right)/2;
		Sort_Merge(arr, left, middle);
		Sort_Merge(arr, middle+1, right);

		Merge(arr, left, middle, right);
	}
}

void Radix(Planet *arr, int left, int right, int size){
	for (int i = size-1; i >= 0; i--){
 		Count_Sort(arr, left, right, i);
	}
}

void Count_Sort(Planet *arr, int left, int right, int idx){
	int elements = right-left;
	int count[26] = {0};
	Planet aux[26][elements];
	Planet output[elements];
	std::string tmp;
	for (int i = left; i < right; i++){
		tmp = arr[i].get_name();
		aux[tmp[idx]-'a'][count[tmp[idx]-'a']].set_name(arr[i].get_name());
		aux[tmp[idx]-'a'][count[tmp[idx]-'a']].set_time(arr[i].get_time());
		count[tmp[idx]-'a']++;
	}
	
	int k = 0;
	
	for (int i = 0; i < 26; i++){
		int shift = 0;
		while (shift < count[i]){
			output[k].set_time(aux[i][shift].get_time());
			output[k].set_name(aux[i][shift].get_name());
			shift++;
			k++;
		}
 	}

	k = 0;

	for (int i = left; i < right; i++){
		arr[i].set_time(output[k].get_time());
		arr[i].set_name(output[k].get_name());
		k++;
	}
}	