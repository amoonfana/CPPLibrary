#include "sorting.h"

void selectionSort(vector<int>& n) {
	int l = n.size();

	int min_idx;
	for (int i = 0; i < l - 1; ++i) {
		min_idx = i;

		for (int j = i + 1; j < l; ++j) {
			if (n[j] < n[min_idx]) { min_idx = j; }
		}

		swap(n[i], n[min_idx]);
	}
}