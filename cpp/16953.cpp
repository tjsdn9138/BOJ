#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	long long A, B; cin >> A >> B;

	queue<long long> q; q.push(A);
	int answer = -1, count = 1;
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			long long cur = q.front(); q.pop();

			if (cur == B) {
				answer = count;
				break;
			}

			long long nxt = cur * 2;
			if (nxt <= B) q.push(nxt);

			nxt = cur * 10 + 1;
			if (nxt <= B) q.push(nxt);
		}

		count++;
	}

	cout << answer;

	return 0;
}