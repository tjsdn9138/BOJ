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
int arr[10];
bool isused[10];

void fcn(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (k != 0 && i <= arr[k - 1]) continue;

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

	fcn(0);

	return 0;
}