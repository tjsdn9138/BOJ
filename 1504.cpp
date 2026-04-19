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

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, E; cin >> N >> E;

	vector<vector<pair<int, int>>> graph(N + 1);
	vector<vector<int>> dist(N + 1, vector<int>(4, INT_MAX));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	vector<int> path(2);
	cin >> path[0] >> path[1];

	if (path[0] == 1) {
		dist[1][1] = 0;
		pq.push({ 0, 1, 1 });
	}
	else if (path[1] == 1) {
		dist[1][2] = 0;
		pq.push({ 0, 1, 2 });
	}
	else {
		dist[1][0] = 0;
		pq.push({ 0, 1, 0 });
	}

	while (!pq.empty()) {
		auto [curDist, cur, index] = pq.top(); pq.pop();

		if (curDist > dist[cur][index]) continue;

		for (auto [nxt, weight] : graph[cur]) {
			int nxtDist = curDist + weight;

			int idx = index;
			if (nxt == path[0]) {
				if (idx == 0) idx = 1;
				else if (idx == 2) idx = 3;
			}
			else if (nxt == path[1]) {
				if (idx == 0) idx = 2;
				else if (idx == 1) idx = 3;
			}

			if (nxtDist < dist[nxt][idx]) {
				dist[nxt][idx] = nxtDist;

				pq.push({ nxtDist, nxt, idx });
			}
		}
	}

	if (dist[N][3] == INT_MAX) cout << -1;
	else cout << dist[N][3];
}