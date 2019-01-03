#include "sorting.h"

void bubbleSort(vector<int>& n) {
	int l = n.size();

	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l - 1 - i; ++j) {
			if (n[j] > n[j + 1]) {
				swap(n[j], n[j + 1]);
			}
		}
	}
}