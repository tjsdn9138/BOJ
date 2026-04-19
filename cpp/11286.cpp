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

vector<int> pq(100001);
int idx = 0;

void push(int n) {
	pq[++idx] = n;

	int temp = idx;
	while (temp > 1) {
		if (abs(pq[temp]) <= abs(pq[temp / 2])) {
			if (abs(pq[temp]) == abs(pq[temp / 2]) && pq[temp] >= pq[temp / 2]) break;

			swap(pq[temp], pq[(int)(temp / 2)]);
			temp /= 2;
		}
		else break;
	}
}

int pop() {
	if (idx == 0) return 0;

	int result = pq[1];
	pq[1] = pq[idx--];

	int temp = 1;
	while (temp <= idx) {
		int largest = temp;
		int l = temp * 2;
		int r = temp * 2 + 1;

		if (l <= idx && abs(pq[largest]) >= abs(pq[l])) {
			if (!(abs(pq[largest]) == abs(pq[l]) && pq[largest] <= pq[l])) {
				largest = l;
			}
		}
		if (r <= idx && abs(pq[largest]) >= abs(pq[r])) {
			if (!(abs(pq[largest]) == abs(pq[r]) && pq[largest] <= pq[r])) {
				largest = r;
			}
		}

		if (largest == temp) break;
		swap(pq[temp], pq[largest]);
		temp = largest;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	for (int r = 0; r < N; r++) {
		int order; cin >> order;

		if (order == 0) cout << pop() << "\n";
		else push(order);
	}
}