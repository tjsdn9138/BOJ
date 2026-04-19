#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

vector<int> heap(100000);
int heapSize;

void push(int n) {
	heap[++heapSize] = n;

	int cur = heapSize;

	while (cur > 1 && heap[cur] < heap[cur / 2]) {
		swap(heap[cur], heap[cur / 2]);
		cur /= 2;
	}
}

int pop() {
	if (heapSize == 0) return 0;

	int r = heap[1];

	heap[1] = heap[heapSize--];

	int cur = 1;
	while (1) {
		int left = cur * 2;
		int right = cur * 2 + 1;
		int least = cur;

		if (left <= heapSize && heap[left] < heap[least]) least = left;
		if (right <= heapSize && heap[right] < heap[least]) least = right;

		if (cur == least) break;
		
		swap(heap[least], heap[cur]);
		cur = least;
	}

	return r;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;

		if (input == 0) cout << pop() << "\n";
		else push(input);
	}
}