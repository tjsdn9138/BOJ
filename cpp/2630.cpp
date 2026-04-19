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

pair<int, int> fcn(int x, int y, int n, vector<vector<int>>& graph) {
	int ans[2] = { 0 };

	if (check(x, y, n, graph)) ans[graph[y][x]]++;
	else {
		int dis = n / 2;

		int dx[4] = { 0, dis, 0, dis };
		int dy[4] = { 0, 0, dis, dis };

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			int a, b;
			tie(a, b) = fcn(nx, ny, dis, graph);

			ans[0] += a;
			ans[1] += b;
		}
	}

	return { ans[0], ans[1] };
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			cin >> graph[i][ii];
		}
	}

	int a, b;
	tie(a, b) = fcn(0, 0, N, graph);

	cout << a << "\n" << b << "\n";

	return 0;
}