#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> v(n + 1, vector<int>(501));
	vector<vector<int>> dp(n + 1, vector<int>(501));
	for (int i = 1; i <= n; i++) {
		for (int ii = 1; ii <= i; ii++) {
			int input; cin >> input;

			v[i][ii] = input;
		}
	}
	dp[1][1] = v[1][1];
	for (int i = 2; i <= n; i++) {
		for (int ii = 1; ii <= i; ii++) {
			if (ii == 1) dp[i][ii] = dp[i - 1][1] + v[i][ii];
			else if (ii == i) dp[i][ii] = dp[i - 1][ii - 1] + v[i][ii];
			else dp[i][ii] = max(dp[i - 1][ii - 1], dp[i - 1][ii]) + v[i][ii];
		}
	}

	int answer = *max_element(dp[n].begin(), dp[n].end());

	cout << answer;

	return 0;
}