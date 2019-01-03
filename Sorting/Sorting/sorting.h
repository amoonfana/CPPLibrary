#pragma once
#include <iostream>
#include <vector>
#include<windows.h>
using namespace std;

typedef unsigned char BYTE;

void bubbleSort(vector<int>& n);
void selectionSort(vector<int>& n);
void insertionSort(vector<int>& n);
void mergeSort(vector<int>& n);
void quickSort(vector<int>& n);
void radixSort(vector<int>& n);