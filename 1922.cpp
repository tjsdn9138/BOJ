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

typedef struct Edge {
    int start;
    int end;
    int weight;
} Edge;

vector<int> parent;

int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int V; cin >> V;
    int E; cin >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        int A, B, C; cin >> A >> B >> C;

        edges[i] = { A, B, C };
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
        });

    parent.resize(V + 1);
    for (int i = 1; i <= V; i++) parent[i] = i;

    int answer = 0;
    int cnt = 0;
    for (Edge e : edges) {
        if (find(e.start) != find(e.end)) {
            unite(e.start, e.end);
            answer += e.weight;
            cnt++;

            if (cnt == V - 1) break;
        }
    }

    cout << answer;
}