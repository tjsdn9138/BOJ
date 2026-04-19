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

    int V, E; cin >> V >> E;
    int start; cin >> start;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> dist(V + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;

        graph[a].push_back({ b, c });
    }

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [curDist, cur] = pq.top(); pq.pop();

        if (dist[cur] < curDist) continue;

        for (auto [nxt, weight] : graph[cur]) {
            int nxtDist = curDist + weight;

            if (nxtDist < dist[nxt]) {
                dist[nxt] = nxtDist;
                pq.push({ nxtDist, nxt });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}