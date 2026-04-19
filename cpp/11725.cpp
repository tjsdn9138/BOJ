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

	vector<vector<int>> tree(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	queue<int> q; q.push(1);
	vector<int> parent(N + 1); parent[1] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nxt : tree[cur]) {
			if (parent[nxt] == 0) {
				q.push(nxt);
				parent[nxt] = cur;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}