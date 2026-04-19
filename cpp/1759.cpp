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
	
	int L, C; cin >> L >> C;

	vector<char> v(C);
	for (int i = 0; i < C; i++) cin >> v[i];
	sort(v.begin(), v.end());

	vector<int> v_check(C);
	for (int i = 0; i < L; i++) v_check[i] = 1;

	do {
		int mo = 0, ja = 0;

		for (int i = 0; i < C; i++) {
			if (v_check[i]) {
				if (v[i] == 'a' ||
					v[i] == 'e' ||
					v[i] == 'i' ||
					v[i] == 'o' ||
					v[i] == 'u') {
					mo++;
				}
				else ja++;
			}
		}

		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < C; i++) if (v_check[i]) cout << v[i];
			cout << "\n";
		}

	} while (prev_permutation(v_check.begin(), v_check.end()));
}