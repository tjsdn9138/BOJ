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

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    vector<int> v(N);
	vector<int> idx(1000001);
	vector<int> lis;

	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) idx[v[i]] = i;

	for (int i = 0; i < N; i++) {
		int cur = v[i];

		auto it = lower_bound(lis.begin(), lis.end(), cur);

		if (it == lis.end()) lis.push_back(cur);
		else *it = cur;
	}

	cout << lis.size() << "\n";
}