#include "include/tree.h"

void heapify(Word *arr, int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l].count > arr[largest].count)
		largest = l;
	if (r < n && arr[r].count > arr[largest].count)
		largest = r;
	if (largest != i){
		//SWAP
		Word tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		//RECURSIVE CALL
		heapify(arr, n, largest);
	}
}

void HeapSort(Word *arr, int n){
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--){
		Word tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heapify(arr, i, 0);
	}
}