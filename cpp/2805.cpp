#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

vector<int> v(1000001);

long long fcn(int height, int N) {
	int left = 0, right = N - 1, index = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (v[mid] > height) {
			index = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	long long answer = 0;
	for (int i = index; i < N; i++) answer += (v[i] - height);

	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.begin() + N);
	int max = v[N - 1];

	int left = 1, right = max, answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long tree = fcn(mid, N);

		if (tree >= M) {
			answer = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << answer;
}