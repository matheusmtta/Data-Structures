#ifndef SORT_
#define SORT_

#include "planet.h"
#include <string>
#include <iostream>

void Merge(Planet *arr, int left, int middle, int right);
void Sort_Merge(Planet *arr, int left, int right);
void Radix(Planet *arr, int left, int right, int size, int elements);
void Count_Sort(Planet *arr, int left, int right, int position, int size, int elements);

#endif