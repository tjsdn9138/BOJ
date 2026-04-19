#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int N;
vector<int> bt(15);
vector<int> v(15);
vector<int> visited(15);

void fcn(int n) {
	if (n == 6) {
		for (int i = 0; i < 6; i++) {
			cout << bt[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		if (n != 0 && bt[n - 1] >= v[i]) continue;

		if (visited[i] == 0) {
			bt[n] = v[i];
			visited[i] = 1;

			fcn(n + 1);

			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	while (true) {
		cin >> N;

		if (N == 0) break;

		for (int i = 0; i < N; i++) cin >> v[i];

		fcn(0);

		cout << "\n";
	}
}