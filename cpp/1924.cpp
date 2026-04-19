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

	string s[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int x, y; cin >> x >> y;

	int cnt = 0;

	for (int i = 0; i < x - 1; i++) cnt += arr[i];
	cnt += y - 1;

	cout << s[cnt % 7];

	return 0;
}