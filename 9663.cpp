#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int N;
int answer = 0;

vector<int> visited1(50);
vector<int> visited2(50);
vector<int> visited3(50);

void fcn(int n) {
	if (n == N) {
		answer++;

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited1[i] && !visited2[n + i] && !visited3[n - i + N - 1]) {
			visited1[i] = 1;
			visited2[n + i] = 1;
			visited3[n - i + N - 1] = 1;

			fcn(n + 1);

			visited1[i] = 0;
			visited2[n + i] = 0;
			visited3[n - i + N - 1] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;

	fcn(0);

	cout << answer;
}