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

	vector<int> v(n);
	vector<vector<int>> dp(n, vector<int>(2));

	for (int i = 0; i < n; i++) cin >> v[i];

    if (n == 1) {
      cout << v[0];

      return 0;
    }

	dp[0][1] = v[0];
	dp[1][0] = v[0];
	dp[1][1] = v[0] + v[1];

	for (int i = 2; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 2][0] + v[i - 1], dp[i - 2][1]) + v[i];
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);
}