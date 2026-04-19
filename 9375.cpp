#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int n; cin >> n;

		map<string, int> m;

		string name, product;
		for (int i = 0; i < n; i++) {
			cin >> name >> product;

			if (m.find(product) != m.end()) m[product] = m[product] + 1;
			else m[product] = 2;
		}

		int answer = 1;
		for (auto a : m) {
			answer *= a.second;
		}
		
		cout << answer - 1 << "\n";
	}
}