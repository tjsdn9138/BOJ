#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;

	int prev = 1;
	int answer = 2;
	int temp;

	if (n == 1) cout << 1;
	else if (n == 2) cout << 2;
	else {
		for (int i = 3; i <= n; i++) {
			temp = answer;
			answer += prev;
			prev = temp;

			answer %= 10007;
			prev %= 10007;
		}

		cout << answer;
	}
}