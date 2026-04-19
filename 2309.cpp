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
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	vector<int> v(9);
	int total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
		total += v[i];
	}
	sort(v.begin(), v.end());

	int a, b;
	for (int i = 0; i < 9; i++) {
		for (int ii = i; ii < 9; ii++) {
			if (i == ii) continue;

			if (total - v[i] - v[ii] == 100) {
				a = i;
				b = ii;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;

		cout << v[i] << "\n";
	}

	return 0;
}