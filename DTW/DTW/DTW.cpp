#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class DTW {
public:
	//Naive solution with time complexity O(n^2)
	float calulate(vector<float>& X, vector<float>& Y) {
		int n = X.size() + 1, m = Y.size() + 1;
		vector<vector<float>> M(n, vector<float>(m));

		for (int i = 1; i < n; ++i) {
			M[i][0] = FLT_MAX;
		}
		for (int j = 1; j < m; ++j) {
			M[0][j] = FLT_MAX;
		}
		M[0][0] = 0;

		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				M[i][j] = pow(X[i-1] - Y[j-1], 2) + min(M[i - 1][j], min(M[i][j - 1], M[i - 1][j - 1]));
				cout << "[" << M[i][j] << "]";
			}
			cout << endl;
		}

		return M[n-1][m-1];
	}

	//A faster version of DTW calculation with Sakoe-Chiba band
	float calulate(vector<float>& X, vector<float>& Y, int w) {
		int n = X.size() + 1, m = Y.size() + 1;
		vector<vector<float>> M(n, vector<float>(m));

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				M[i][j] = FLT_MAX;
			}
		}
		M[0][0] = 0;

		m -= 1;
		for (int i = 1; i < n; ++i) {
			for (int j = max(1, i - w); j <= min(m, i + w); ++j) {
				M[i][j] = pow(X[i - 1] - Y[j - 1], 2) + min(M[i - 1][j], min(M[i][j - 1], M[i - 1][j - 1]));
				cout << "[" << M[i][j] << "]";
			}
			cout << endl;
		}

		return M[n - 1][m - 1];
	}
};

void main() {
	DTW dtw;

	vector<float> X = { 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 2, 2, 1, 1, 0, 0 };
	vector<float> Y = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 2, 1, 1, 0, 0, 0, 0 };

	cout << dtw.calulate(X, Y, 3) << endl;

	system("pause");
}
