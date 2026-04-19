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
	
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 10 - i;
	}
	
	for (int i = 1; i < n; i++) {
		for (int ii = 9; ii >= 0; ii--) {
			dp[i][ii] = dp[i - 1][ii];

			if (ii != 9) dp[i][ii] += dp[i][ii + 1];

            dp[i][ii] %= 10007;
		}
	}

	cout << dp[n - 1][0] % 10007;
}