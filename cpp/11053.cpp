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

	vector<int> input(N);
	vector<int> dp(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int ii = 0; ii < i; ii++) {
			if (input[i] > input[ii]) dp[i] = max(dp[i], dp[ii] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}