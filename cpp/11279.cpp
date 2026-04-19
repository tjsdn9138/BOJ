#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	priority_queue<int> pq;

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;

		if (input == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(input);
	}
}