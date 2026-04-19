#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, answer = 0;
	cin >> N >> M;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	vector<vector<int>> graph(N, vector<int>(N));
	vector<vector<int>> vst(N, vector<int>(N));
	graph[0][0] = 1;
	vst[0][0] = 1;
	answer++;

	multimap<int, int> light;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		light.insert({ b * N + a, d * N + c });
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		auto range = light.equal_range(y * N + x);
		for (auto it = range.first; it != range.second;) {
			int f = it->first;
			int s = it->second;

			if (graph[s / N][s % N] == 0) answer++;
			graph[s / N][s % N] = 1;

			if (vst[s / N][s % N]) q.push({ s % N, s / N });
			else {
				for (int i = 0; i < 4; i++) {
					int xx = s % N + dx[i];
					int yy = s / N + dy[i];

					if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;

					if (vst[yy][xx]) {
						q.push({ xx, yy });
						break;
					}
				}
			}
			
			it = light.erase(it);
		}

		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vst[ny][nx]) continue;
			if (graph[ny][nx] == 0) continue;

			vst[ny][nx] = 1;
			q.push({ nx, ny });
		}
	}

	cout << answer;

	return 0;
}