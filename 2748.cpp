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

	int n; cin >> n;

	vector<long long> v(n + 1);
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i <= n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[n];

	return 0;
}