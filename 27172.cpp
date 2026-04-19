#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	vector<int> v(N);
	int m = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];

		m = max(m, v[i]);
	}

	vector<int> score(m + 1);
	for (int i = 0; i < N; i++) {
		int num = v[i];

		for (int ii = num * 2; ii <= m; ii += num) score[ii]--;
		if (num != 1) score[1]++;
		for (int ii = 2; ii <= sqrt(num); ii++) {
			if (num % ii == 0) {
				score[ii]++;
				if (num / ii != ii) score[num / ii]++;
			}
		}
	}

	for (int i = 0; i < N; i++) cout << score[v[i]] << " ";
}