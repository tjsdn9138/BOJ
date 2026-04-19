#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, m; cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string input; cin >> input;

		for (int ii = 0; ii < m; ii++) v[i][ii] = input[ii] - '0';
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < m; ii++) {
			if (v[i][ii]) {
				if (i == 0 || ii == 0) {
					dp[i][ii] = 1;

					if (dp[i][ii] > max) max = dp[i][ii];

					continue;
				}
				
				dp[i][ii] = min(dp[i - 1][ii - 1],
					min(dp[i - 1][ii], dp[i][ii - 1])) + 1;

				if (dp[i][ii] > max) max = dp[i][ii];
			}
		}
	}

	cout << max * max;
}