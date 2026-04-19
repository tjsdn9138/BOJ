#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;

	vector<vector<int>> V(N + 1, vector<int>(N + 1));
	vector<vector<int>> v(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int ii = 1; ii <= N; ii++) {
			cin >> V[i][ii];
			v[i][ii] = v[i][ii - 1] + V[i][ii];
		}
	}

	for (int i = 0; i < M; i++) {
		int w; cin >> w;
		if (w == 1) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

			int answer = 0;
			for (int i = x1; i <= x2; i++) {
				answer += v[i][y2] - v[i][y1 - 1];
			}

			cout << answer << "\n";
		}
		else {
			int x, y, c; cin >> x >> y >> c;

			int minus = V[x][y] - c;

			V[x][y] = c;
			for (int i = y; i <= N; i++) v[x][i] -= minus;
		}
	}
}