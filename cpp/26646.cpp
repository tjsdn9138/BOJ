#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int fcn(int a, int b) {
	int plus = a + b;
	int minus = abs(a - b);

	return plus * plus + minus * minus;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	for (int i = 0; i < N - 1; i++) {
		answer += fcn(arr[i], arr[i + 1]);
	}

	cout << answer;

	return 0;
}