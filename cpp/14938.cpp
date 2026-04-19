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

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, r; cin >> n >> m >> r;

    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) cin >> value[i];

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 100000));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < r; i++) {
        int a, b, c; cin >> a >> b >> c;

        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= n; ii++) {
            for (int iii = 1; iii <= n; iii++) {
                if (dist[ii][i] + dist[i][iii] < dist[ii][iii]) {
                    dist[ii][iii] = dist[ii][i] + dist[i][iii];
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int total = 0;

        for (int ii = 1; ii <= n; ii++) {
            if (dist[i][ii] <= m) total += value[ii];
        }

        if (total > answer) answer = total;
    }

    cout << answer;
}