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

	int N, K; cin >> N >> K;

	vector<pair<int, int>> v(N + 1);
	for (int i = 1; i <= N; i++) {
		int W, V; cin >> W >> V;

		v[i] = { W, V };
	}

	vector<vector<int>> dp(N + 1, vector<int>(K + 1));
	for (int i = 1; i <= N; i++) {
		int weight = v[i].first;
		int value = v[i].second;

		for (int ii = 1; ii <= K; ii++) {
			if (weight <= ii) {
				dp[i][ii] = max(dp[i - 1][ii], dp[i - 1][ii - weight] + value);
			}
			else dp[i][ii] = dp[i - 1][ii];
		}
	}

	cout << dp[N][K];
}