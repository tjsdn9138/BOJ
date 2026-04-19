#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int bfs(vector<vector<char>> v, int N, int M) {
	queue<tuple<char, int, int>> q;
	vector<vector<int>> visited(N, vector<int>(M, -1));

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			if (v[i][ii] == 'G') {
				q.push({ 'G', i, ii });
				visited[i][ii] = 0;
			}
			else if (v[i][ii] == 'R') {
				q.push({ 'R', i, ii });
				visited[i][ii] = 0;
			}
		}
	}

	int level = 0;
	while (!q.empty()) {
		int size = q.size();
		level++;

		for (int s = 0; s < size; s++) {
			char color;
			int r, c;

			tie(color, r, c) = q.front(); q.pop();

			if (v[r][c] == 'F') continue;

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
				if (v[nr][nc] == '0' || v[nr][nc] == 'F') continue;

				if (v[nr][nc] == '2' || v[nr][nc] == '1') {
					v[nr][nc] = color;
					visited[nr][nc] = level;

					q.push({ color, nr, nc });
				}
				else {
					if (v[nr][nc] != color && visited[nr][nc] == level) {
						result++;

						v[nr][nc] = 'F';
					}
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, M, G, R; cin >> N >> M >> G >> R;

	vector<vector<char>> v(N, vector<char>(M));
	vector<pair<int, int>> canB;
	vector<char> p_canB;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			cin >> v[i][ii];

			if (v[i][ii] == '2') {
				canB.push_back({ i, ii });
				p_canB.push_back('2');
			}
		}
	}

	for (int i = 0; i < G; i++) p_canB[i] = 'G';
	for (int i = 0; i < R; i++) p_canB[p_canB.size() - 1 - i] = 'R';
	sort(p_canB.begin(), p_canB.end());

	int answer = 0;
	do {
		for (int i = 0; i < p_canB.size(); i++) {
			int r = canB[i].first;
			int c = canB[i].second;

			v[r][c] = p_canB[i];
		}

		int temp = bfs(v, N, M);
		if (temp > answer) answer = temp;

	} while (next_permutation(p_canB.begin(), p_canB.end()));

	cout << answer;
}