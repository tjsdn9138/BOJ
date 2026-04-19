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
	
	int R, C; cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int ii = 0; ii < C; ii++) {
			cout << "*";
		}
		cout << "\n";
	}
}