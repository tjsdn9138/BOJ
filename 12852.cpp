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

	vector<int> dp(N + 1, -1); dp[N] = 0; dp[0] = 1;
	vector<int> prev(N + 1);

	queue<int> q; q.push(N);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == 1) break;

		if (cur % 3 == 0) {
			if (dp[cur / 3] == -1) {
				dp[cur / 3] = dp[cur] + 1;
				prev[cur / 3] = cur;
				q.push(cur / 3);
			}
		}
		if (cur % 2 == 0) {
			if (dp[cur / 2] == -1) {
				dp[cur / 2] = dp[cur] + 1;
				prev[cur / 2] = cur;
				q.push(cur / 2);
			}
		}
		if (cur - 1 > 0 && dp[cur - 1] == -1) {
			dp[cur - 1] = dp[cur] + 1;
			prev[cur - 1] = cur;
			q.push(cur - 1);
		}
	}

	cout << dp[1] << "\n";

	int index = 1;
	stack<int> s; 
	while (1) {
		s.push(index);

		if (index == N) break;

		index = prev[index];
	}

	while (!s.empty()) {
		cout << s.top() << " "; s.pop();
	}

	return 0;
}