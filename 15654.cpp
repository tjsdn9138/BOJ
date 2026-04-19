#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<int> input;
int arr[10];
bool isused[10001];

void fcn(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int x = 0; x < N; x++) {
		int i = input[x];

		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			fcn(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	int in;
	for (int i = 0; i < N; i++) {
		cin >> in;
		input.push_back(in);
	}
	sort(input.begin(), input.end());

	fcn(0);

	return 0;
}