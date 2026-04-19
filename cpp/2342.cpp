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

	vector<vector<int>> power(5, vector<int>(5));
	power[0][1] = 2; power[0][2] = 2; power[0][3] = 2; power[0][4] = 2;
	power[1][1] = 1; power[1][2] = 3; power[1][3] = 4; power[1][4] = 3;
	power[2][1] = 3; power[2][2] = 1; power[2][3] = 3; power[2][4] = 4;
	power[3][1] = 4; power[3][2] = 3; power[3][3] = 1; power[3][4] = 3;
	power[4][1] = 3; power[4][2] = 4; power[4][3] = 3; power[4][4] = 1;

	vector<int> input;
	while (true) {
		int temp; cin >> temp;

		if (temp == 0) break;

		input.push_back(temp);
	}

	vector<vector<int>> dp(input.size(), vector<int>(5, INT_MAX / 2));
	dp[0][0] = 2;
	for (int i = 1; i < dp.size(); i++) {
		int target = input[i];

		int temp = INT_MAX;
		for (int ii = 0; ii <= 4; ii++) {
			temp = min(temp, dp[i - 1][ii] + power[ii][target]);
		}
		dp[i][input[i - 1]] = temp;

		dp[i][0] = dp[i - 1][0] + power[input[i - 1]][target];
		dp[i][1] = min(dp[i][1], min(dp[i - 1][1] + power[input[i - 1]][target],
			dp[i - 1][target] + power[input[i - 1]][1]));
		dp[i][2] = min(dp[i][2], min(dp[i - 1][2] + power[input[i - 1]][target],
			dp[i - 1][target] + power[input[i - 1]][2]));
		dp[i][3] = min(dp[i][3], min(dp[i - 1][3] + power[input[i - 1]][target],
			dp[i - 1][target] + power[input[i - 1]][3]));
		dp[i][4] = min(dp[i][4], min(dp[i - 1][4] + power[input[i - 1]][target],
			dp[i - 1][target] + power[input[i - 1]][4]));

		dp[i][target] = INT_MAX / 2;
	}

	cout << *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}