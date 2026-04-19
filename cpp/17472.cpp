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

vector<int> parent;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (a > b) parent[a] = b;
		else parent[b] = a;
	}
}

bool isConnected(int n) {
	int value = parent[1];

	for (int i = 2; i <= n; i++) {
		if (value != find(i)) return false;
	}

	return true;
}

int main() {
	int N, M; cin >> N >> M;

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };

	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			cin >> map[i][ii];

			if (map[i][ii] == 1) map[i][ii] = -1;
		}
	}

	// row, col, num, dir, len, bridge
	queue<tuple<int, int, int, int, int, int>> q;

	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			if (map[i][ii] == -1) {
				map[i][ii] = ++temp;

				queue<pair<int, int>> tq;
				tq.push({ i, ii });

				while (!tq.empty()) {
					int r = tq.front().first;
					int c = tq.front().second;
					tq.pop();

					for (int iii = 0; iii < 4; iii++) {
						int nr = r + dr[iii];
						int nc = c + dc[iii];

						if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
						if (map[nr][nc] == 0) q.push({ r, c, temp, iii, 0, 0 });
						if (map[nr][nc] != -1) continue;

						map[nr][nc] = temp;
						tq.push({ nr, nc });
					}
				}
			}
		}
	}

	parent.resize(temp + 1);
	for (int i = 1; i <= temp; i++) parent[i] = i;

	int answer = 0;
	while (!q.empty()) {
		auto [row, col, num, dir, len, bridge] = q.front(); q.pop();
		row += dr[dir];
		col += dc[dir];

		if (row < 0 || col < 0 || row >= N || col >= M) continue;

		if (map[row][col] == -1) {
			q.push({ row, col, num, dir, ++len, ++bridge });
		}
		else if (map[row][col]) {
			if (len > 1 && (find(map[row][col]) != find(num))) {
				unite(num, map[row][col]);
				answer += len;

				row -= dr[dir];
				col -= dc[dir];
				while (map[row][col] != num) {
					map[row][col] = -1;
					row -= dr[dir];
					col -= dc[dir];
				}

				if (isConnected(temp)) {
					cout << answer;

					return 0;
				}
			}
		}
		else q.push({ row, col, num, dir, ++len, bridge });
	}

	cout << -1;
}