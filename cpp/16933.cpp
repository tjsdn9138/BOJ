#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	cin.ignore();

	vector<vector<int>> graph(N, vector<int>(M, 0));
	vector<vector<vector<int>>> vst(N, vector<vector<int>>(M, vector<int>(2, 0)));

	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		for (int ii = 0; ii < M; ii++) {
			graph[i][ii] = line[ii] - '0';
		}
	}


	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	vst[0][0][0] = 1;
	vst[0][0][1] = 0;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int cnt;
	int count = 0;
	int dn = 0;
	while (!q.empty()) {
		cnt = q.size();
		count++;

		if (dn) dn = 0;
		else dn = 1;

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
				if (graph[ny][nx] == 1) {
					if (dn == 0) continue;
					if (ncheck == K) continue;
					else ncheck++;
				}
				if (vst[ny][nx][0] == 1 && ncheck >= vst[ny][nx][1]) continue;
				
				q.push({ ny, nx, ncheck });
				vst[ny][nx][0] = 1;
				vst[ny][nx][1] = ncheck;
			}

			if (dn == 0 && check < K) {
				q.push({ y, x, check });
			}
		}
	}


	cout << -1;

	return 0;
}