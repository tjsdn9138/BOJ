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

    int N, M, X; cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
    for (int i = 1; i <= N; i++) {
        pq.push({ 0, i, i });
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;

        graph[a].push_back({ b, c });
    }

    while (!pq.empty()) {
        auto [curDist, cur, start] = pq.top(); pq.pop();

        if (curDist > dist[cur][start]) continue;

        for (auto [nxt, weight] : graph[cur]) {
            int nxtDist = curDist + weight;

            if (nxtDist < dist[nxt][start]) {
                dist[nxt][start] = nxtDist;
                pq.push({ nxtDist, nxt, start });
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        answer = max(answer, dist[X][i] + dist[i][X]);
    }

    cout << answer;
}