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

vector<vector<char>> v(11, vector<char>(11));
vector<vector<vector<vector<bool>>>> visited(11,
	vector<vector<vector<bool>>>(11,
		vector<vector<bool>>(11,
			vector<bool>(11))));

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int push(pair<int, int>& p, int n) {
	int cnt = 0;

	while (true) {
		if (v[p.first + dr[n]][p.second + dc[n]] == '#') return cnt;

		p.first += dr[n];
		p.second += dc[n];
		cnt++;

		if (v[p.first][p.second] == 'O') return -1;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;

	queue<tuple<int, pair<int, int>, pair<int, int>>> q;

	pair<int, int> red, blue, hole;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			cin >> v[i][ii];

			if (v[i][ii] == 'B') blue = { i, ii };
			if (v[i][ii] == 'R') red = { i, ii };
			if (v[i][ii] == 'O') hole = { i, ii };
		}
	}

	q.push({ 0, red, blue });
	visited[red.first][red.second][blue.first][blue.second] = true;
	while (!q.empty()) {
		auto [level, curR, curB] = q.front(); q.pop();

		if (level > 10) {
			cout << -1;

			return 0;
		}
		if (curR == hole) {
			cout << level;

			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nxtLevel = level + 1;
			pair<int, int> nxtR = curR;
			pair<int, int> nxtB = curB;

			int moveR = push(nxtR, i);
			int moveB = push(nxtB, i);

			if (visited[nxtR.first][nxtR.second][nxtB.first][nxtB.second]) continue;
			if (moveB == -1) continue;

			if (nxtR == nxtB) {
				if (i == 0 && curB.first < curR.first) {
					nxtB = { nxtB.first - dr[i], nxtB.second - dc[i] };
					moveB--;
				}
				else if (i == 1 && curB.first > curR.first) {
					nxtB = { nxtB.first - dr[i], nxtB.second - dc[i] };
					moveB--;
				}
				else if (i == 2 && curB.second < curR.second) {
					nxtB = { nxtB.first - dr[i], nxtB.second - dc[i] };
					moveB--;
				}
				else if (i == 3 && curB.second > curR.second) {
					nxtB = { nxtB.first - dr[i], nxtB.second - dc[i] };
					moveB--;
				}
				else {
					nxtR = { nxtR.first - dr[i], nxtR.second - dc[i] };
					moveR--;
				}
			}

			if (moveR || moveB) {
				q.push({ nxtLevel, nxtR, nxtB });
				visited[nxtR.first][nxtR.second][nxtB.first][nxtB.second] = true;
			}
		}
	}

	cout << -1;
}