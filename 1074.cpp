#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int fcn(int n, int r, int c) {
	if (n == 0) return 0;

	int half = 1 << n - 1;

	if (c < half && r < half) return fcn(n - 1, r, c);
	if (c >= half && r < half) return fcn(n - 1, r, c - half) + 1 * (half * half);
	if (c < half && r >= half) return fcn(n - 1, r - half, c) + 2 * (half * half);
	if (c >= half && r >= half) return fcn(n - 1, r - half, c - half) + 3 * (half * half);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, r, c;
	cin >> N >> r >> c;
	
	cout << fcn(N, r, c);

	return 0;
}