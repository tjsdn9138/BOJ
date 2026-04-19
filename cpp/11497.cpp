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


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		
		vector<int> v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v.begin(), v.end());

		int left = v[0];
		int right = v[1];
		int answer = v[1] - v[0];
		for (int i = 2; i < N; i++) {
			if (left < right) {
				answer = max(answer, v[i] - left);
				left = v[i];
			}
			else {
				answer = max(answer, v[i] - right);
				right = v[i];
			}
		}
		answer = max(answer, abs(right - left));

		cout << answer << "\n";
	}
}