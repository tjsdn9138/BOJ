#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int C; cin >> C;

	for (int c = 0; c < C; c++) {
		int N; cin >> N;

		vector<int> v(N);
		int total = 0;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			total += v[i];
		}

		int avg = total / N;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] > avg) cnt++;
		}

		double answer = 100.0 * cnt / N;

		printf("%.3f%%\n", answer);
	}
}