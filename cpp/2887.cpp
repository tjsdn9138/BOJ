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

    vector<tuple<int, int, int>> v(N);
    vector<tuple<int, int, int, int>> tv(N);
    vector<bool> visited(N);
    vector<vector<pair<int, int>>> graph(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;

        v[i] = { a, b, c };
        tv[i] = { a, b, c, i };
    }

    sort(tv.begin(), tv.end());
    for (int i = 0; i < N - 1; i++) {
        int temp = abs(get<0>(tv[i]) - get<0>(tv[i + 1]));
        graph[get<3>(tv[i])].push_back({ get<3>(tv[i + 1]), temp});
        graph[get<3>(tv[i + 1])].push_back({ get<3>(tv[i]), temp });
    }
    sort(tv.begin(), tv.end(), [](auto& a, auto& b) {
        return get<1>(a) < get<1>(b);
        });
    for (int i = 0; i < N - 1; i++) {
        int temp = abs(get<1>(tv[i]) - get<1>(tv[i + 1]));
        graph[get<3>(tv[i])].push_back({ get<3>(tv[i + 1]), temp });
        graph[get<3>(tv[i + 1])].push_back({ get<3>(tv[i]), temp });
    }
    sort(tv.begin(), tv.end(), [](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
        });
    for (int i = 0; i < N - 1; i++) {
        int temp = abs(get<2>(tv[i]) - get<2>(tv[i + 1]));
        graph[get<3>(tv[i])].push_back({ get<3>(tv[i + 1]), temp });
        graph[get<3>(tv[i + 1])].push_back({ get<3>(tv[i]), temp });
    }

    pq.push({0, 0});
    int answer = 0;
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        answer += cost;

        for (auto [v, w] : graph[u]) {
            if (visited[v] == false) pq.push({ w, v });
        }
    }

    cout << answer;
}