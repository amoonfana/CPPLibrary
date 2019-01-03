#include "sorting.h"

void printResult(vector<int>& n) {
	int l = n.size();

	for (int i = 0; i < l; ++i) {
		cout << n[i] << " ";
	}
	cout << endl;
}

int main() {
	long start, end;
	int l = 10000000;
	vector<int> n = vector<int>(l), n_t = vector<int>(l);
	for (int i = 0; i < l; ++i) {
		n[i] = rand() % l;
	}

	//bubbleSort(n_t);
	//selectionSort(n_t);
	//insertionSort(n_t);

	n_t = n;
	start = GetTickCount();
	mergeSort(n_t);
	end = GetTickCount();
	cout << (end - start) << endl;

	n_t = n;
	start = GetTickCount();
	quickSort(n_t);
	end = GetTickCount();
	cout << (end - start) << endl;

	n_t = n;
	start = GetTickCount();
	radixSort(n_t);
	end = GetTickCount();
	cout << (end - start) << endl;

	//printResult(n);
}