#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int dr[3] = { 0, -1, 0 };
int dc[3] = { -1, 0, 1 };

int N, M, D;
int answer = 0;
int result = 0;
vector<vector<int>> input(20, vector<int>(20));
vector<vector<int>> v;
vector<pair<int, int>> einput;
vector<pair<int, int>> enemy;

void print() {
	cout << "debug\n";
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) cout << v[i][ii] << " ";
		cout << "\n";
	}
}

void bfs(int n, set<pair<int, int>>& isdied) {
	int dis = -1;

	queue<pair<int, int>> q;
	q.push({ N, n });

	vector<vector<bool>> visited(N + 1, vector<bool>(M + 1));

	while (!q.empty()) {
		dis++;
		if (dis > D) return;
		int rep = q.size();

		for (int rp = 0; rp < rep; rp++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			if (dis <= D && v[r][c]) {
				isdied.insert({ r, c });

				return;
			}

			for (int i = 0; i < 3; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nc >= M) continue;
				if (visited[nr][nc]) continue;

				visited[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}
}

void shoot(int t, int tt, int ttt) {
	set<pair<int, int>> isdied;

	bfs(t, isdied);
	bfs(tt, isdied);
	bfs(ttt, isdied);

	for (auto x : isdied) {
		v[x.first][x.second] = 0;
		result++;

		for (auto it = enemy.begin(); it != enemy.end(); ) {
			pair cur = *it;

			if (cur.first == x.first && cur.second == x.second) {
				it = enemy.erase(it);
			}
			else it++;
		}
	}
}

void move() {
	for (auto it = enemy.begin(); it != enemy.end(); ) {
		pair cur = *it;
		v[cur.first][cur.second]--;

		if (cur.first + 1 >= N) {
			it = enemy.erase(it);
		}
		else {
			*it = { cur.first + 1, cur.second };
			it++;
			v[cur.first + 1][cur.second]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			cin >> input[i][ii];

			if (input[i][ii]) einput.push_back({i, ii});
		}
	}

	for (int t = 0; t < M; t++) {
		for (int tt = 0; tt < M; tt++) {
			if (t == tt) continue;

			for (int ttt = 0; ttt < M; ttt++) {
				if (t == ttt || tt == ttt) continue;

				v = input;
				enemy = einput;

				result = 0;
				while (!enemy.empty()) {
					shoot(t, tt, ttt);
					move();
				}
				answer = max(answer, result);
			}
		}
	}

	cout << answer;
}