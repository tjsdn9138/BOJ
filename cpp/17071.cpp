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

    int N, K; cin >> N >> K;

    vector<vector<int>> visited(500001, vector<int>(2, -1));
    queue<int> q;
    q.push(N); visited[N][0] = 0;

    int time = -1;
    int answer = INT_MAX;
    while (!q.empty()) {
        time++;
        K += time;
        
        if (K > 500000) {
            if (answer == INT_MAX) cout << -1;
            else cout << answer;

            return 0;
        }

        if (visited[K][0] != -1) {
            if (time % 2 == 0) answer = min(answer, time);
            else if (K < 250000 && K % 2 == 0 && K < time - visited[K][0]) answer = min(answer, time);
        }
        if (visited[K][1] != -1) {
            if (time % 2 == 1) answer = min(answer, time);
            else if (K < 250000 && K % 2 == 0 && K < time - visited[K][1]) answer = min(answer, time);
        }

        int rep = q.size();
        for (int i = 0; i < rep; i++) {
            int cur = q.front(); q.pop();

            if (K > 500000) {
                if (answer == INT_MAX) cout << -1;
                else cout << answer;

                return 0;
            }
            
            if (cur == K) {
                cout << min(answer, time);

                return 0;
            }

            if (cur * 2 <= 500000 && visited[cur * 2][(time + 1) % 2] == -1) {
                q.push(cur * 2);
                visited[cur * 2][(time + 1) % 2] = time + 1;
            }

            if (cur > 0 && visited[cur - 1][(time + 1) % 2] == -1) {
                q.push(cur - 1);
                visited[cur - 1][(time + 1) % 2] = time + 1;
            }

            if (cur < 500000 && visited[cur + 1][(time + 1) % 2] == -1) {
                q.push(cur + 1);
                visited[cur + 1][(time + 1) % 2] = time + 1;
            }
        }
    }

    cout << -1;
}