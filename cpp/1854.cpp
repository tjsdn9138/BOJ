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

    int V, E, K; cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<vector<int>> dist(V + 1, vector<int>(110, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> count(V + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;

        graph[a].push_back({ b, c });
    }

    dist[1][0] = 0;
    count[1]++;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [curDist, cur] = pq.top(); pq.pop();

        for (auto [nxt, weight] : graph[cur]) {
            int nxtDist = curDist + weight;

            if (count[nxt] < K) {
                dist[nxt][count[nxt]++] = nxtDist;
                sort(dist[nxt].begin(), dist[nxt].begin() + count[nxt]);
                pq.push({ nxtDist, nxt });
            }
            else {
                if (nxtDist < dist[nxt][K - 1]) {
                    dist[nxt][K] = nxtDist;
                    sort(dist[nxt].begin(), dist[nxt].begin() + K + 1);
                    pq.push({ nxtDist, nxt });
                }
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i][K - 1] == INT_MAX) cout << -1 << "\n";
        else cout << dist[i][K - 1] << "\n";
    }
}