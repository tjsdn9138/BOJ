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

	int total = 0;

	int temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		
		temp = max(temp, 40);

		total += temp;
	}

	cout << total / 5;

	return 0;
}