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

tuple<int, int, int> fcn(int x, int y, int n, vector<vector<int>>& graph) {
	int ans[3] = { 0 };

	if (check(x, y, n, graph)) ans[graph[y][x] + 1]++;
	else {
		int dis = n / 3;

		int dx[9] = { 0, dis, dis * 2, 0, dis, dis * 2, 0, dis, dis * 2 };
		int dy[9] = { 0, 0, 0, dis, dis, dis, dis * 2, dis * 2, dis * 2 };

		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			int a, b, c;
			tie(a, b, c) = fcn(nx, ny, dis, graph);

			ans[0] += a;
			ans[1] += b;
			ans[2] += c;
		}
	}

	return { ans[0], ans[1], ans[2] };
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

	int a, b, c;
	tie(a, b, c) = fcn(0, 0, N, graph);

	cout << a << "\n" << b << "\n" << c << "\n";

	return 0;
}