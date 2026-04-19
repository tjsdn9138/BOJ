#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int N;
    cin >> N;

    int max = 0;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) {
            cin >> graph[i][ii];
            if (graph[i][ii] > max) max = graph[i][ii];
        }
    }

    int temp = graph[0][0];
    int flag = 0;
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) {
            if (graph[i][ii] != temp) flag = 1;
        }
    }
    if (flag == 0) {
        cout << 1;
        return 0;
    }

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    int answer = 0;
    for (int i = 1; i < max; i++) {
        queue<pair<int, int>> q;
        vector<vector<int>> vst(N, vector<int>(N, 0));

        int count = 0;
        for (int ii = 0; ii < N; ii++) {
            for (int iii = 0; iii < N; iii++) {
                if (graph[ii][iii] > i && vst[ii][iii] == 0) {
                    q.push({ iii, ii });
                    vst[ii][iii] = 1;
                    count++;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int iv = 0; iv < 4; iv++) {
                            int nx = x + dx[iv];
                            int ny = y + dy[iv];

                            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if (graph[ny][nx] <= i || vst[ny][nx] == 1) continue;

                            q.push({ nx, ny });
                            vst[ny][nx] = 1;
                        }
                    }
                }
            }
        }

        if (count > answer) answer = count;
    }

    cout << answer;
}