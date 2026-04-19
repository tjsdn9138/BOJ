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

	int N; cin >> N;
	vector<pair<int, int>> v(N + 2);
	vector<vector<int>> prev(N + 2);
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;

		if (i + a <= N + 1) prev[i + a].push_back(i);

		v[i] = { a, b };
	}

	vector<int> dp(N + 2);
	for (int i = 1; i <= N + 1; i++) {
		dp[i] = dp[i - 1];
		int temp = dp[i];

		for (int x : prev[i]) temp = max(dp[x] + v[x].second, temp);

		dp[i] = temp;
	}
	
	cout << dp[N + 1];

	return 0;
}