#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool check(vector<vector<int>> v) {
	for (auto line : v) {
		for (auto value : line) {
			if (value != 0) return true;
		}
	}

	return false;
}

void melt(vector<vector<int>>& v) {
	vector<vector<int>> temp(v.size(), vector<int>(v[0].size()));
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < v.size(); i++) {
		for (int ii = 0; ii < v[i].size(); ii++) {
			if (v[i][ii] != 0) {
				int count = 0;

				for (int iii = 0; iii < 4; iii++) {
					if (v[i + dx[iii]][ii + dy[iii]] == 0) count++;
				}

				if (count > v[i][ii]) count = v[i][ii];

				temp[i][ii] = count;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int ii = 0; ii < v[0].size(); ii++) {
			v[i][ii] -= temp[i][ii];
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) cin >> graph[i][ii];
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int answer = 0;
	while (check(graph)) {		
		vector<vector<int>> vst(graph.size(), vector<int>(graph[0].size()));

		int flag = 0;
		for (int i = 0; i < graph.size(); i++) {
			for (int ii = 0; ii < graph[0].size(); ii++) {
				if (graph[i][ii] && vst[i][ii] == 0) {
					if (flag == 0) {
						flag = 1;
						queue<pair<int, int>> q;
						q.push({ ii, i });
						vst[i][ii] = 1;

						while (!q.empty()) {
							int x = q.front().first;
							int y = q.front().second;
							q.pop();

							for (int iii = 0; iii < 4; iii++) {
								int nx = x + dx[iii];
								int ny = y + dy[iii];

								if (graph[ny][nx] == 0 || vst[ny][nx]) continue;

								q.push({ nx, ny });
								vst[ny][nx] = 1;
							}
						}
					}
					else {
						cout << answer++;
						return 0;
					}
				}
			}
		}

		answer++;
		melt(graph);
	}

	cout << 0;
	return 0;
}