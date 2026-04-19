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
#include <climits>
#include <numeric>

using namespace std;

bool compare(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	vector<string> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	sort(v.begin(), v.end(), compare);

	if (v[0] == "0") {
		cout << 0;
		return 0;
	}
	for (auto x : v) cout << x;
}