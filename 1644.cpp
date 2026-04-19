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

	int N; cin >> N;

	vector<bool> era(N + 1, true);
	era[0] = false; era[1] = false;

	for (int i = 2; i <= sqrt(N); i++) {
		for (int ii = i * i; ii <= N; ii += i) era[ii] = false;
	}

	int start = 2;
	int end = 3;
	int total = 5;

	int answer = era[N] ? 1 : 0;
	while (start < end) {
		if (total < N) {
			do {
				end++;
			} while (era[end] == false);

			total += end;
		}
		else {
			if (total == N) answer++;

			total -= start;

			do {
				start++;
			} while (era[start] == false);
		}
	}
	cout << answer;
}