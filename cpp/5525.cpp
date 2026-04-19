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

	int N; cin >> N;
	int M; cin >> M;
	string S; cin >> S;

	vector<int> dp(M, 1);

	int target = N * 2 + 1;
	int answer = 0;
	for (int i = 2; i < M; i++) {
		if (S[i] == 'I' && S[i - 1] == 'O' && S[i - 2] == 'I') {
			dp[i] = dp[i - 2] + 2;

			if (dp[i] >= target) answer++;
		}
	}

	cout << answer;
}