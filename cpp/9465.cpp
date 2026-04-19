#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	for (int t = 0; t < T; t++) {

		int N; cin >> N;
		vector<vector<int>> v(2, vector<int>(N));
		for (int i = 0; i < 2; i++) {
			for (int ii = 0; ii < N; ii++) cin >> v[i][ii];
		}

		vector<vector<int>> dp(3, vector<int>(N));
		dp[0][0] = v[0][0]; dp[1][0] = v[1][0]; dp[2][0] = 0;
		for (int i = 1; i < N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + v[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + v[1][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}

		cout << max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1])) << "\n";
	}

	return 0;
}