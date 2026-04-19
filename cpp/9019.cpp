#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int D(int n) { return (2 * n) % 10000; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + (n / 1000); }
int R(int n) { return (n % 10) * 1000 + (n / 10); }

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	while (T--) {
		int A, B; cin >> A >> B;

		queue<int> q;
		vector<int> visited(10000);
		vector<pair<int, char>> prev(10000);

		q.push(A);
		visited[A] = 1;
		while (!q.empty()) {
			int num = q.front(); q.pop();

			if (num == B) {
				int p = prev[B].first;
				stack<char> s; s.push(prev[B].second);

				while (p != A) {
					s.push(prev[p].second);
					p = prev[p].first;
				}

				while (!s.empty()) {
					cout << s.top(); s.pop();
				}

				break;
			}

			int nxt;

			nxt = D(num);
			if (visited[nxt] == 0) {
				q.push(nxt);
				visited[nxt] = 1;
				prev[nxt] = { num, 'D' };
			}
			
			nxt = L(num);
			if (visited[nxt] == 0) {
				q.push(nxt);
				visited[nxt] = 1;
				prev[nxt] = { num, 'L' };
			}
			
			nxt = R(num);
			if (visited[nxt] == 0) {
				q.push(nxt);
				visited[nxt] = 1;
				prev[nxt] = { num, 'R' };
			}

			nxt = S(num);
			if (visited[nxt] == 0) {
				q.push(nxt);
				visited[nxt] = 1;
				prev[nxt] = { num, 'S' };
			}
		}

		cout << "\n";
	}
}