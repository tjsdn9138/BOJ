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

	int T; cin >> T;

	int n; cin >> n;
	vector<int> A(n + 1);
	vector<int> hapA(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		hapA[i] = hapA[i - 1] + A[i];
	}

	int m; cin >> m;
	vector<int> B(m + 1);
	vector<int> hapB(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		hapB[i] = hapB[i - 1] + B[i];
	}

	vector<int> setA;
	for (int i = 1; i <= n; i++) {
		for (int ii = 0; ii < i; ii++) setA.push_back(hapA[i] - hapA[ii]);
	}
	sort(setA.begin(), setA.end());

	vector<int> setB;
	for (int i = 1; i <= m; i++) {
		for (int ii = 0; ii < i; ii++) setB.push_back(hapB[i] - hapB[ii]);
	}
	sort(setB.begin(), setB.end());

	long long answer = 0;
	int rep = setA.size();
	for (int i = 0; i < rep; i++) {
		int temp = setA[i];

		int left = 0;
		int right = setB.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			int result = temp + setB[mid];

			if (result == T) {
				answer += upper_bound(setB.begin(), setB.end(), setB[mid]) - lower_bound(setB.begin(), setB.end(), setB[mid]);
				break;
			}
			else if (result > T) right = mid - 1;
			else left = mid + 1;
		}
	}

	cout << answer;
}