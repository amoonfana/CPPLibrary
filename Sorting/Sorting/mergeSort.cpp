#include "sorting.h"

void merge(vector<int>& n, int s, int e, vector<int>& t) {
	if (s >= e) { return; }

	int mid = (s + e) / 2;
	merge(n, s, mid, t);
	merge(n, mid + 1, e, t);

	int l = 0, i_s = s, i_e = mid, j_s = mid + 1, j_e = e;
	while (i_s <= i_e && j_s <= j_e) {
		if (n[i_s] < n[j_s]) {
			t[l++] = n[i_s++];
		}
		else {
			t[l++] = n[j_s++];
		}
	}
	while (i_s <= i_e) {
		t[l++] = n[i_s++];
	}
	while (j_s <= j_e) {
		t[l++] = n[j_s++];
	}

	for (int i = 0; i < l; ++i) {
		n[s + i] = t[i];
	}
}

void mergeSort(vector<int>& n) {
	int l = n.size();
	vector<int> t = vector<int>(l);

	merge(n, 0, l - 1, t);
}