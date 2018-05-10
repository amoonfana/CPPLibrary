#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP {
public:
	//Original KMP algorithm, of which the time complexity is optimal but requiring O(ML) memory space
	void getTable(string p, vector<vector<int>>& dfa, vector<int>& c2i) {
		int m = p.size(), l = 0;

		c2i = vector<int>(256, -1);
		for (int i = 0; i < m; ++i) {
			if (c2i[p[i]] < 0) {
				c2i[p[i]] = l++;
			}
		}

		dfa = vector<vector<int>>(l);
		for (int i = 0; i < l; ++i) {
			dfa[i] = vector<int>(m);
		}

		dfa[c2i[p[0]]][0] = 1;
		for (int i = 0, j = 1; j < m; ++j) {
			for (int k = 0; k < l; ++k) {
				dfa[k][j] = dfa[k][i];
			}
			dfa[c2i[p[j]]][j] = j + 1;
			i = dfa[c2i[p[j]]][i];
		}
	}

	int search1(string s, string p) {
		int i, j, n = s.size(), m = p.size();
		vector<vector<int>> dfa;
		vector<int> c2i;
		getTable(p, dfa, c2i);
		
		for (i = 0, j = 0; i < n && j < m; i++) {
			j = dfa[c2i[s[i]]][j];
		}

		if (j == m) { return i - m; }
		else { return -1; }
	}

	//Improved KMP algorithm, of which the time complexity is slightly slower but requiring O(M) memory space only
	void getNext(string p, vector<int>& next) {
		int i = 0, j = -1, m = p.size();
		next = vector<int>(m + 1);
		next[0] = -1;

		while (i < m) {
			if (j == -1 || p[i] == p[j]) {
				if (p[++i] != p[++j]) {
					next[i] = j;
				}
				else {
					next[i] = next[j];
				}
			}
			else {
				j = next[j];
			}
		}
	}

	int search2(string s, string p) {
		int i = 0, j = 0, n = s.size(), m = p.size();
		vector<int> next;
		getNext(p, next);

		while (i < n && j < m) {
			if (j == -1 || s[i] == p[j]) {
				i += 1;
				j += 1;
			}
			else {
				j = next[j];
			}
		}

		if (j == m) {
			//cout << s.substr(i - j, m) << endl;
			return (i - j);
		}

		return -1;
	}
};

void main() {
	KMP kmp;

	//string p("ABCDABD");
	//string s("BBC ABCDAB ABCDABCDABDE");
	string p("ABABAC");
	string s("AABACAABABACAA");

	cout << kmp.search1(s, p) << endl;
	cout << kmp.search2(s, p) << endl;

	system("pause");
}