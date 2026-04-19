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

    vector<pair<int, int>> v(N);
	vector<int> idx(500001);
    vector<int> prev(N, -1);
	vector<bool> check(N);
	vector<int> lis;

	for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) idx[v[i].second] = i;

	for (int i = 0; i < N; i++) {
		int cur = v[i].second;

		auto it = lower_bound(lis.begin(), lis.end(), cur);

		if (it == lis.end()) {
			lis.push_back(cur);
			if (lis.size() >= 2) prev[i] = idx[lis[lis.size() - 2]];
		}
		else {
			*it = cur;
			if (lis[0] != cur) prev[i] = idx[*(it - 1)];
		}
	}

	int index = idx[lis[lis.size() - 1]];
	for (int i = 0; i < lis.size(); i++) {
		check[index] = true;
		index = prev[index];
	}

	cout << N - lis.size() << "\n";
	for (int i = 0; i < N; i++) {
		if (check[i] == false) cout << v[i].first << "\n";
	}
}