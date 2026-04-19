#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, P;
	cin >> N >> M >> P;
	vector<int> md(P + 1);
	for (int i = 1; i <= P; i++) {
		cin >> md[i];
		if (md[i] > (M - 1) + (N - 1)) md[i] = M + N - 2;
	}
	cin.ignore();

	vector<vector<char>> graph(N, vector<char>(M));
	queue<tuple<int, int, int>> q;
	vector<tuple<int, int, int>> temp;

	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		for (int ii = 0; ii < M; ii++) {
			graph[i][ii] = line[ii];

			if ('1' <= graph[i][ii] && graph[i][ii] <= '9') temp.push_back({ ii, i, graph[i][ii] - '0' });
		}
	}
	sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
		return get<2>(a) < get<2>(b);
		});
	for (auto val : temp) q.push(val);

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	
	while (!q.empty()) {
		int x, y, p;
		tie(x, y, p) = q.front();
		q.pop();

		queue<pair<int, int>> tq;
		tq.push({ x, y });

		while (!q.empty()) {
			int tx, ty, tp;
			tie(tx, ty, tp) = q.front();
			if (tp == p) {
				tq.push({ tx, ty });
				q.pop();
			}
			else break;			
		}
		
		for (int m = 0; m < md[p]; m++) {
			int cnt = tq.size();

			for (int c = 0; c < cnt; c++) {
				int xx = tq.front().first;
				int yy = tq.front().second;
				tq.pop();

				for (int i = 0; i < 4; i++) {
					int nx = xx + dx[i];
					int ny = yy + dy[i];

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
					if (graph[ny][nx] != '.') continue;

					graph[ny][nx] = p + '0';
					q.push({ nx, ny, p });
					tq.push({ nx, ny });
				}
			}
		}
	}

	vector<int> answer(P + 1);
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			if ('1' <= graph[i][ii] && graph[i][ii] <= '9') answer[graph[i][ii] - '0']++;
		}
	}

	for (int i = 1; i <= P; i++) cout << answer[i] << ' ';

	return 0;
}