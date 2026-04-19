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

    int N; cin >> N;

    vector<int> v(N);
    vector<vector<int>> dist(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) cin >> dist[i][ii];
    }

    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) {
            for (int iii = 0; iii < N; iii++) {
                if (dist[ii][iii] == 0) {
                    if (dist[ii][i] == 1 && dist[i][iii] == 1) {
                        dist[ii][iii] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) cout << dist[i][ii] << " ";
        cout << "\n";
    }
}