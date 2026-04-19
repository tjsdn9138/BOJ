#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i];

    // dp[x][y] => y부터 x까지 팰 여부
    vector < vector < bool >> dp(N + 1, vector<bool>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int ii = i; ii >= 1; ii--) {
            if (i == ii) dp[i][ii] = true;
            else if (i - 1 == ii && v[i] == v[ii]) dp[i][ii] = true;
            else if (v[i] == v[ii] && dp[i - 1][ii + 1]) dp[i][ii] = true;
        }
    }

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int start, end; cin >> start >> end;

        if (dp[end][start]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}