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

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };

	int N, M; cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		for (int ii = 0; ii < M; ii++) v[i][ii] = input[ii] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			if (v[i][ii] == 0 && visited[i][ii] == false) {
				set<pair<int, int>> temp;
				queue<pair<int, int>> q;

				visited[i][ii] = true;
				q.push({ i, ii });
				
				int cnt = 1;
				while (!q.empty()) {
					auto [r, c] = q.front(); q.pop();

					for (int iii = 0; iii < 4; iii++) {
						int nr = r + dr[iii];
						int nc = c + dc[iii];

						if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
						if (visited[nr][nc]) continue;
						
						if (v[nr][nc]) temp.insert({ nr, nc });
						else {
							cnt++;
							visited[nr][nc] = true;
							q.push({ nr, nc });
						}
					}
				}

				for (pair x : temp) v[x.first][x.second] += cnt;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) cout << v[i][ii] % 10;
		cout << "\n";
	}
}