#include "sorting.h"

int maxbit(vector<int>& n, int l)
{
	int d = 1, p = 10;
	for (int i = 0; i < l; ++i) {
		while (n[i] >= p) {
			p *= 10;
			++d;
		}
	}
	return d;
}

void radixSort(vector<int>& n) {
	int l = n.size(), d = maxbit(n, l), radix = 1;
	vector<int> n_t = vector<int>(l), ht = vector<int>(10);

	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < 10; ++j) {
			ht[j] = 0;
		}
		for (int j = 0; j < l; ++j) {
			++ht[(n[j] / radix) % 10];
		}
		for (int j = 1; j < 10; ++j) {
			ht[j] += ht[j - 1];
		}
		for (int j = l - 1; j >= 0; --j) {
			n_t[--ht[(n[j] / radix) % 10]] = n[j];
		}
		for (int j = 0; j < l; ++j) {
			n[j] = n_t[j];
		}

		radix *= 10;
	}
}