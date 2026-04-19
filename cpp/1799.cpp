#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int N;
int answer = 0;
int bbae = 0;
vector<vector<int>> v(15, vector<int>(15));
vector<int> visited(100);

void fcn(int n) {
	int flag = 0;

	if (n - bbae > answer) answer = n - bbae;
	if (n == 2 * N - 1) return;

	if (n < N) {
		for (int i = 0; i <= n; i++) {
			int r = i;
			int c = n - i;

			if (v[r][c] == 0) continue;

			if (visited[r - c + N - 1] == 0) {
				flag = 1;

				visited[r - c + N - 1] = 1;

				fcn(n + 1);

				visited[r - c + N - 1] = 0;
			}
		}
	}
	else {
		for (int i = n - N + 1; i <= N - 1; i++) {
			int r = i;
			int c = n - i;

			if (v[r][c] == 0) continue;

			if (visited[r - c + N - 1] == 0) {
				flag = 1;

				visited[r - c + N - 1] = 1;

				fcn(n + 1);

				visited[r - c + N - 1] = 0;
			}
		}
	}

	if (flag == 0) {
		bbae++;

		fcn(n + 1);

		bbae--;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) cin >> v[i][ii];
	}

	fcn(0);

	cout << answer;
}