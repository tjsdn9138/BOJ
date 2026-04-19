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
#include <climits>
#include <numeric>

using namespace std;

vector<vector<int>> v(26, vector<int>(2, -1));

void preorder(int n) {
	cout << (char)(n + 'A');
	if (v[n][0] != -1) preorder(v[n][0]);
	if (v[n][1] != -1) preorder(v[n][1]);
}

void inorder(int n) {
	if (v[n][0] != -1) inorder(v[n][0]);
	cout << (char)(n + 'A');
	if (v[n][1] != -1) inorder(v[n][1]);
}

void postorder(int n) {
	if (v[n][0] != -1) postorder(v[n][0]);
	if (v[n][1] != -1) postorder(v[n][1]);
	cout << (char)(n + 'A');
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	
	for (int i = 0; i < N; i++) {
		char a, b, c; cin >> a >> b >> c;

		if (b != '.') v[a - 'A'][0] = b - 'A';
		if (c != '.') v[a - 'A'][1] = c - 'A';
	}

	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0);
}