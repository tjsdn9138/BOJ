#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int N, M, answer;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(vector<vector<int>> graph, queue<pair<int, int>> q) {
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int ii = 0; ii < 4; ii++) {
				int nx = x + dx[ii];
				int ny = y + dy[ii];

				if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
				if (graph[ny][nx] != 0) continue;

				graph[ny][nx] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			if (graph[i][ii] == 0) temp++;
		}
	}
	answer = max(temp, answer);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> graph(10, vector<int>(10));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			cin >> graph[i][ii];
			
			if (graph[i][ii] == 2) q.push({ ii, i });
		}
	}

	for (int i = 0; i < N * M - 2; i++) {
		int x1 = i % M; int y1 = i / M;
		if (graph[y1][x1] != 0) continue;

		for (int ii = i + 1; ii < N * M - 1; ii++) {
			int x2 = ii % M; int y2 = ii / M;
			if (graph[y2][x2] != 0) continue;

			for (int iii = ii + 1; iii < N * M; iii++) {
				int x3 = iii % M; int y3 = iii / M;
				if (graph[y3][x3] != 0) continue;

				graph[y1][x1] = 1;
				graph[y2][x2] = 1;
				graph[y3][x3] = 1;

				bfs(graph, q);

				graph[y1][x1] = 0;
				graph[y2][x2] = 0;
				graph[y3][x3] = 0;
			}
		}
	}

	cout << answer;
}