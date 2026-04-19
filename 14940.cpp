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

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };

	int n, m; cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m, -1));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < m; ii++) {
			cin >> v[i][ii];

			if (v[i][ii] == 2) {
				q.push({ i, ii });
				visited[i][ii] = 0;
			}
			if (v[i][ii] == 0) visited[i][ii] = 0;
		}
	}

	int time = 0;
	while (!q.empty()) {
		time++;

		int rep = q.size();
		for (int R = 0; R < rep; R++) {
			auto [r, c] = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
				if (visited[nr][nc] != -1) continue;

				visited[nr][nc] = time;
				q.push({ nr, nc });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < m; ii++) cout << visited[i][ii] << " ";
		cout << "\n";
	}
}