#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int h, w, answer = 0;
		cin >> h >> w;

		vector<vector<char>> graph(h, vector<char>(w, 0));
		queue<pair<int, int>> q;
		set<pair<int, int>> s;
		vector<int> k(26);

		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };

		for (int i = 0; i < h; i++) {
			string line;
			cin >> line;

			for (int ii = 0; ii < w; ii++) {
				graph[i][ii] = line[ii];				
			}
		}

		string line;
		cin >> line;
		int size = line.size();
		if (line[0] != '0') {
			for (int i = 0; i < size; i++) {
				char c = line[i] - 'a';
				k[c] = 1;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int ii = 0; ii < w; ii++) {
				if (i == 0 || ii == 0 || i == h - 1 || ii == w - 1) {
					int nx = ii;
					int ny = i;

					if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
					if (graph[ny][nx] == '*') continue;
					else if (graph[ny][nx] == '$') answer++;
					else if ('A' <= graph[ny][nx] && graph[ny][nx] <= 'Z') {
						if (k[graph[ny][nx] + 32 - 'a'] == 0) {
							s.insert({ nx, ny });
							continue;
						}
					}
					else if ('a' <= graph[ny][nx] && graph[ny][nx] <= 'z') {
						if (k[graph[ny][nx] - 'a'] == 0) {
							for (auto it = s.begin(); it != s.end();) {
								int xx = it->first;
								int yy = it->second;

								if (graph[yy][xx] == graph[ny][nx] - 32) {
									graph[yy][xx] = '*';
									q.push({ xx, yy });
									it = s.erase(it);
								}
								else it++;
							}
						}

						k[graph[ny][nx] - 'a'] = 1;
					}

					graph[ny][nx] = '*';
					q.push({ nx, ny });
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				if (graph[ny][nx] == '*') continue;
				else if (graph[ny][nx] == '$') answer++;
				else if ('A' <= graph[ny][nx] && graph[ny][nx] <= 'Z') {
					if (k[graph[ny][nx] + 32 - 'a'] == 0) {
						s.insert({ nx, ny });
						continue;
					}
				}
				else if ('a' <= graph[ny][nx] && graph[ny][nx] <= 'z') {
					if (k[graph[ny][nx] - 'a'] == 0) {
						for (auto it = s.begin(); it != s.end();) {
							int xx = it->first;
							int yy = it->second;

							if (graph[yy][xx] == graph[ny][nx] - 32) {
								graph[yy][xx] = '*';
								q.push({ xx, yy });
								it = s.erase(it);
							}
							else it++;
						}
					}

					k[graph[ny][nx] - 'a'] = 1;
				}

				graph[ny][nx] = '*';
				q.push({ nx, ny });
			}
		}

		cout << answer << "\n";
	}

	return 0;
}