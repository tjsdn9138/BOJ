#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<int> graph[1001];
vector<int> visit(1001);

void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;

	for (int nxt : graph[v]) {
		if (visit[nxt] == 0) {
			dfs(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, V; cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << "\n";

	queue<int> q; q.push(V);
	vector<int> visited(1001);
	while (!q.empty()) {
		int num = q.front(); q.pop();

		cout << num << " ";

		for (int nxt : graph[num]) {
			if (visited[nxt] == 0) {
				q.push(nxt);
				visited[nxt] = 1;
			}
		}

		visited[num] = 1;
	}
	cout << "\n";
}