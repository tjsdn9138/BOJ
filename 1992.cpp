#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int x, int y, int n, vector<vector<int>>& graph) {
	int num;

	for (int i = y; i < y + n; i++) {
		for (int ii = x; ii < x + n; ii++) {
			if (i == y && ii == x) num = graph[i][ii];

			if (graph[i][ii] != num) return false;
		}
	}

	return true;
}

void fcn(int x, int y, int n, vector<vector<int>>& graph) {
	if (check(x, y, n, graph)) cout << graph[y][x];
	else {
		int dis = n / 2;

		int dx[4] = { 0, dis, 0, dis };
		int dy[4] = { 0, 0, dis, dis };

		cout << "(";
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			fcn(nx, ny, dis, graph);
		}
		cout << ")";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	cin.ignore();

	vector<vector<int>> graph(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		for (int ii = 0; ii < N; ii++) {
			graph[i][ii] = line[ii] - '0';
		}
	}

	fcn(0, 0, N, graph);

	return 0;
}