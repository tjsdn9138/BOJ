#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<long long> p(101);

	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	for (int i = 6; i <= 100; i++) {
		p[i] = p[i - 5] + p[i - 1];
	}

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		cout << p[N] << "\n";
	}
}