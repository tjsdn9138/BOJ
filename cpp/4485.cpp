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

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };

	int problem = 0;
	while (true) {
		problem++;

		int N; cin >> N;

		if (N == 0) return 0;

		vector<vector<int>> graph(N, vector<int>(N));
		vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

		for (int i = 0; i < N; i++) {
			for (int ii = 0; ii < N; ii++) cin >> graph[i][ii];
		}

		pq.push({ graph[0][0], 0, 0});
		dist[0][0] = graph[0][0];

		while (!pq.empty()) {
			auto [curDist, r, c] = pq.top(); pq.pop();

			if (curDist > dist[r][c]) continue;

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

				int nxtDist = curDist + graph[nr][nc];
				if (nxtDist < dist[nr][nc]) {
					dist[nr][nc] = nxtDist;
					pq.push({ nxtDist, nr, nc });
				}
			}
		}

		cout << "Problem " << problem << ": " << dist[N - 1][N - 1] << "\n";
	}
}