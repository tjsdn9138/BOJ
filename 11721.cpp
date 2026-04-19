#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	string input; cin >> input;

	int index = 0;

	for (int i = 0; i < input.size(); i++) {
		cout << input[index++];

		if (index % 10 == 0) cout << "\n";
	}

	return 0;
}