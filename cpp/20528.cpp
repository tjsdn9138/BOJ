#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N;

	string input; cin >> input;
	char check = input[0];

	for (int i = 0; i < N - 1; i++) {
		cin >> input;

		if (check != input[0]) {
			cout << 0;

			return 0;
		}
	}
	
	cout << 1;
}