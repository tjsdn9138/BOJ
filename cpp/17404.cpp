#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	vector<vector<int>> cost(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < 3; ii++) cin >> cost[i][ii];
	}

	vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3)));
	dp[0][0][0] = cost[0][0];
	dp[0][1][0] = 10000;
	dp[0][2][0] = 10000;

	dp[0][0][1] = 10000;
	dp[0][1][1] = cost[0][1];
	dp[0][2][1] = 10000;

	dp[0][0][2] = 10000;
	dp[0][1][2] = 10000;
	dp[0][2][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][2][0]) + cost[i][0];
		dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][2][0]) + cost[i][1];
		dp[i][2][0] = min(dp[i - 1][0][0], dp[i - 1][1][0]) + cost[i][2];

		dp[i][0][1] = min(dp[i - 1][1][1], dp[i - 1][2][1]) + cost[i][0];
		dp[i][1][1] = min(dp[i - 1][0][1], dp[i - 1][2][1]) + cost[i][1];
		dp[i][2][1] = min(dp[i - 1][0][1], dp[i - 1][1][1]) + cost[i][2];

		dp[i][0][2] = min(dp[i - 1][1][2], dp[i - 1][2][2]) + cost[i][0];
		dp[i][1][2] = min(dp[i - 1][0][2], dp[i - 1][2][2]) + cost[i][1];
		dp[i][2][2] = min(dp[i - 1][0][2], dp[i - 1][1][2]) + cost[i][2];
	}

	vector<int> temp;
	temp.push_back(dp[N - 1][0][1]);
	temp.push_back(dp[N - 1][0][2]);
	temp.push_back(dp[N - 1][1][0]);
	temp.push_back(dp[N - 1][1][2]);
	temp.push_back(dp[N - 1][2][0]);
	temp.push_back(dp[N - 1][2][1]);

	cout << *min_element(temp.begin(), temp.end());
}