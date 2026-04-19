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

	int N, M; cin >> N >> M;

	vector<vector<int>> v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		v[b].push_back(a);
	}

	int mx = 0;
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		queue<int> q; q.push(i);
		vector<bool> visited(N + 1); visited[i] = true;

		int count = 1;
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int nxt : v[cur]) {
				if (visited[nxt]) continue;

				visited[nxt] = true;
				count++;
				q.push(nxt);
			}
		}

		if (count > mx) {
			mx = count;
			answer.clear();
			answer.push_back(i);
		}
		else if (count == mx) answer.push_back(i);
	}

	for (int x : answer) cout << x << " ";
}