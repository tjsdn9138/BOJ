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
    int M; cin >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;

        graph[a].push_back({ b, c });
    }

    int start, end; cin >> start >> end;

    vector<int> cost(N + 1, INT_MAX);
    cost[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [curCost, cur] = pq.top(); pq.pop();

        if (cost[cur] < curCost) continue;

        for (auto [nxt, cst] : graph[cur]) {
            int nxtCost = curCost + cst;

            if (nxtCost < cost[nxt]) {
                cost[nxt] = nxtCost;
                pq.push({ nxtCost, nxt });
            }
        }
    }

    cout << cost[end];
}