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
	string s1, s2; cin >> s1 >> s2;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (s1[i] == s2[i]) answer++;
	}

	cout << answer;
}