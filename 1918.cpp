#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string input;
	cin >> input;

	stack<char> s;

	for (auto x : input) {
		if (isalpha(x)) cout << x;
		else if (x == '(') s.push(x);
		else if (x == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			if (!s.empty() && s.top() == '(') s.pop();
		}
		else {
			if (s.empty()) s.push(x);
			else {
				while (!s.empty() && s.top() != '(' && !((s.top() == '+' || s.top() == '-') && (x == '*' || x == '/'))) {
					cout << s.top();
					s.pop();
				}

				s.push(x);
			}
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}