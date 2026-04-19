#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int fcn(int n) {
	int answer = 0;

	for (int i = 1; i <= (int)sqrt(n); i++) {
		if (n % i == 0) answer++;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N;

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer += fcn(i);
	}

	cout << answer;
}