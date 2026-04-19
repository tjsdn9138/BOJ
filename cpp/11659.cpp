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

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	for (int i = 0; i < M; i++) {
		int from, to; cin >> from >> to;

		cout << v[to] - v[from - 1] << "\n";
	}
}