#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	cin.ignore();

	vector<vector<int>> graph(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		for (int ii = 0; ii < M; ii++) {
			graph[i][ii] = line[ii] - '0';
		}
	}


	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	graph[0][0] = 2;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int cnt;
	int count = 0;
	while (!q.empty()) {
		cnt = q.size();
		count++;

		for (int c = 0; c < cnt; c++) {
			int x = get<1>(q.front());
			int y = get<0>(q.front());
			int check = get<2>(q.front());
			q.pop();

			if (x == M - 1 && y == N - 1) {
				cout << count;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ncheck = check;
				
				if (nx >= M || ny >= N || nx < 0 || ny < 0) continue;
				if (graph[ny][nx] == 3) continue;
				else if (graph[ny][nx] == 2 && check == 1) continue;
				else if (graph[ny][nx] == 1) {
					if (ncheck == 1) continue;
					else {
						ncheck = 1;
						q.push({ ny, nx, ncheck });
						continue;
					}
				}

				if (ncheck == 0) graph[ny][nx] = 3;
				else graph[ny][nx] = 2;
				q.push({ ny, nx, ncheck });
			}
		}
	}


	cout << -1;

	return 0;
}