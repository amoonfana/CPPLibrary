#include "sorting.h"

void insertionSort(vector<int>& n) {
	int l = n.size();

	for (int i = 1; i < l; ++i) {
		int key = n[i];

		int j;
		for (j = i - 1; j >= 0 && n[j] > key; --j) {
			n[j + 1] = n[j];
		}
		n[j + 1] = key;
	}
}