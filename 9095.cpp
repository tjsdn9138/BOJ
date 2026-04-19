#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<int> dp(11);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] += dp[i - 3];
		dp[i] += dp[i - 2];
		dp[i] += dp[i - 1];
	}

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int n; cin >> n;

		cout << dp[n] << "\n";
	}
}