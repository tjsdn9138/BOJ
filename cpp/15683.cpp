#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int N, M, answer;
vector<tuple<int, int, int>> cctv;

vector<vector<int>> check(vector<vector<int>> v, int r, int c, int dr, int dc) {
    int nr = r;
    int nc = c;

    while (true) {
        nr += dr;
        nc += dc;

        if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
        if (v[nr][nc] == 6) break;
        if (v[nr][nc] >= 1 && v[nr][nc] <= 5) continue;
        if (v[nr][nc] == -1) continue;

        v[nr][nc] = -1;
    }

    return v;
}

void bt(int n, vector<vector<int>> v) {
    if (n == cctv.size()) {
        int result = 0;

        for (int i = 0; i < N; i++) {
            for (int ii = 0; ii < M; ii++) {
                if (v[i][ii] == 0) result++;
            }
        }

        if (result < answer) answer = result;

        return;
    }

    int num, r, c;
    tie(num, r, c) = cctv[n];

    vector<vector<int>> nxt;
    if (num == 5) {
        nxt = { {0, 1, 2, 3} };
    }
    else if (num == 4) {
        nxt = { {1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2} };
    }
    else if (num == 3) {
        nxt = { {0, 2}, {0, 3}, {1, 2}, {1, 3} };
    }
    else if (num == 2) {
        nxt = { {0, 1}, {2, 3} };
    }
    else if (num == 1) {
        nxt = { { 0 }, { 1 }, { 2 }, { 3 } };
    }

    for (int i = 0; i < nxt.size(); i++) {
        vector<vector<int>> vec(v);
        
        for (auto temp : nxt[i]) {
            vec = check(vec, r, c, dr[temp], dc[temp]);
        }

        bt(n + 1, vec);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    answer = N * M;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < M; ii++) {
            cin >> v[i][ii];

            if (v[i][ii] >= 1 && v[i][ii] <= 5) {
                cctv.push_back({ v[i][ii], i, ii });
            }
        }
    }

    bt(0, v);

    cout << answer;
}