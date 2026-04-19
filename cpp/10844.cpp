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
#include <climits>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;

	vector<vector<int>> dp(n, vector<int>(10, 1));
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		for (int ii = 0; ii <= 9; ii++) {
			dp[i][ii] = 0;

			if (ii != 9) dp[i][ii] += dp[i - 1][ii + 1];
			if (ii != 0) dp[i][ii] += dp[i - 1][ii - 1];

			dp[i][ii] %= 1000000000;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[n - 1][i]) % 1000000000;
	}

	cout << answer;
}