#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int K, W, H;
	cin >> K;
	cin >> W >> H;

	vector<vector<int>> graph(H, vector<int>(W));
	vector<vector<int>> vst(H, vector<int>(W, K + 1));
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < H; i++) {
		for (int ii = 0; ii < W; ii++) cin >> graph[i][ii];
	}
	q.push({ 0, 0, 0 });
	for (int i = 0; i <= K; i++) vst[0][0] = 0;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int jdx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int jdy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

	int cnt;
	int answer = -1;
	while (!q.empty()) {
		cnt = q.size();
		answer++;

		for (int c = 0; c < cnt; c++) {
			int x, y, k;
			tie(x, y, k) = q.front();
			q.pop();

			if (x == W - 1 && y == H - 1) {
				cout << answer;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nk = k;

				if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
				if (nk >= vst[ny][nx] || graph[ny][nx] == 1) continue;

				q.push({ nx, ny, nk });
				vst[ny][nx] = nk;
			}

			if (k != K) {
				for (int i = 0; i < 8; i++) {
					int nx = x + jdx[i];
					int ny = y + jdy[i];
					int nk = k + 1;

					if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
					if (nk >= vst[ny][nx] || graph[ny][nx] == 1) continue;

					q.push({ nx, ny, nk });
					vst[ny][nx] = nk;
				}
			}
		}
	}

	cout << -1;

	return 0;
}