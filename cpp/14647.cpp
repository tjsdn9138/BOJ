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

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<int> row(n);
	vector<int> col(m);

	vector<vector<string>> graph(n, vector<string>(m));
	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < m; ii++) {
			cin >> graph[i][ii];

			int cnt = count(graph[i][ii].begin(), graph[i][ii].end(), '9');

			row[i] += cnt;
			col[ii] += cnt;
		}
	}

	int answer1 = accumulate(row.begin(), row.end(), 0) - *max_element(row.begin(), row.end());
	int answer2 = accumulate(col.begin(), col.end(), 0) - *max_element(col.begin(), col.end());

	cout << min(answer1, answer2);
}