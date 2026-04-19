#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

void fcn(int n, int from, int to) {
	int other = 6 - to - from;

	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	else {
		fcn(n - 1, from, other);
		cout << from << " " << to << "\n";
		fcn(n - 1, other, to);
		return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int K;
	cin >> K;

	
	cout << (int)pow(2, K) - 1 << "\n";
	fcn(K, 1, 3);

	return 0;
}