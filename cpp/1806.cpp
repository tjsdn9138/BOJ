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

	int N, S; cin >> N >> S;

	vector<int> v(N + 1);
	vector<int> hap(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		hap[i] = hap[i - 1] + v[i];
	}

	int answer = 100001;
	for (int i = 1; i <= N; i++) {
		int left = 0;
		int right = i - 1;

		int temp;
		while (left <= right) {
			int mid = (left + right) / 2;

			temp = hap[i] - hap[mid];
			if (temp >= S) {
				answer = min(answer, i - mid);
				left = mid + 1;
			}
			else right = mid - 1;
		}
	}

	if (answer == 100001) cout << 0;
	else cout << answer;
}