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

	int A, B, C; cin >> A >> B >> C;

	if (B >= C) cout << -1;
	else cout << A / (C - B) + 1;

	return 0;
}