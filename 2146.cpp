#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	queue<tuple<int, int, int, int>> q;

	vector<vector<vector<int>>> graph(N, vector<vector<int>>(N, vector<int>(2)));
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			cin >> graph[i][ii][0];
			if (graph[i][ii][0] == 1) graph[i][ii][0] = -1;
		}
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int num = 1;
	queue<pair<int, int>> tq;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			if (graph[i][ii][0] == -1) {
				tq.push({ ii, i });
				graph[i][ii][0] = num;

				while (!tq.empty()) {
					int x = tq.front().first;
					int y = tq.front().second;
					tq.pop();

					for (int iii = 0; iii < 4; iii++) {
						int nx = x + dx[iii];
						int ny = y + dy[iii];

						if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
						if (graph[ny][nx][0] != -1) continue;

						tq.push({ nx, ny });
						q.push({ nx, ny, 0, num });
						graph[ny][nx][0] = num;
					}
				}
				
				q.push({ ii, i, 0, num });
				num++;
			}
		}
	}


	while (!q.empty()) {
		int x, y, len, n;
		tie(x, y, len, n) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nlen = len + 1;

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (graph[ny][nx][0] == n) continue;
			if (graph[ny][nx][0]) {
				cout << nlen + graph[ny][nx][1] - 1;
				return 0;
			}

			q.push({ nx, ny, nlen, n });
			graph[ny][nx][0] = n;
			graph[ny][nx][1] = nlen;
		}
	}


	return 0;
}