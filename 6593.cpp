#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int fcn() {
	int L, R, C;
	cin >> L >> R >> C;
	cin.ignore();

	if (!L && !R && !C) return 0;

	queue<tuple<int, int, int>> q;

	vector<vector<vector<char>>> graph(
		L, vector<vector<char>>(R, vector<char>(C))
	);

	tuple<int, int, int> target;
	for (int i = 0; i < L; i++) {
		for (int ii = 0; ii < R; ii++) {
			string line;
			getline(cin, line);

			if (line.empty()) {
				ii--;
				continue;
			}

			for (int iii = 0; iii < C; iii++) {
				graph[i][ii][iii] = line[iii];
				if (graph[i][ii][iii] == 'S') q.push({ iii, ii, i });
				if (graph[i][ii][iii] == 'E') target = { i, ii, iii };
			}
		}


	}

	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	int cnt;
	int time = -1;
	while (!q.empty()) {
		cnt = q.size();
		time++;

		for (int c = 0; c < cnt; c++) {
			int x, y, z;
			tie(x, y, z) = q.front();
			q.pop();


			if (tie(z, y, x) == target) {
				cout << "Escaped in " << time << " minute(s)." << '\n';
				return 1;
			}

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L) continue;
				if (graph[nz][ny][nx] == '#' || graph[nz][ny][nx] == 'S') continue;

				graph[nz][ny][nx] = 'S';
				q.push({ nx, ny, nz });
			}
		}
	}

	cout << "Trapped!" << '\n';
	return -1;
}

int main() {
	while (1) {
		if (fcn() == 0) break;
	}
	
	return 0;
}