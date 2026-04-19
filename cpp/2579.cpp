#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> dp(N);
	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[0], v[1]) + v[2];
	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]) + v[i];
	}

	cout << dp[N - 1];
}