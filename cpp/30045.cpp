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
	
	int N; cin >> N;
	int answer = 0;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input.find("OI") != string::npos || input.find("01") != string::npos) {
			answer++;
		}
	}

	cout << answer;
}