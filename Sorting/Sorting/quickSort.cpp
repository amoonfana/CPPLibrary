#include "sorting.h"

void quick(vector<int>& n, int s, int e) {
	if (s >= e) { return; }

	int i = s, j = e, pivot = n[s];
	while (i < j) {
		while (i < j && n[j] >= pivot) {
			--j;
		}
		n[i] = n[j];

		while (i < j && n[i] < pivot) {
			++i;
		}
		n[j] = n[i];
	}

	n[i] = pivot;
	quick(n, s, i - 1);
	quick(n, i + 1, e);
}

void quickSort(vector<int>& n) {
	int l = n.size();

	quick(n, 0, l - 1);
}