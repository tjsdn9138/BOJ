#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int N;
int answer = 0;

void pushBlock(vector<vector<int>>& v, int& r, int& c, int drc) {
    int nr = r;
    int nc = c;

    int cnt = 0;
    while (true) {
        nr += dr[drc];
        nc += dc[drc];
        cnt++;

        if (nr < -1 || nc < -1 || nr > N || nc > N) break;
        if ((nr == -1 || nc == -1 || nr == N || nc == N) || v[nr][nc] != 0) {
            if (cnt > 1) {
                v[nr - dr[drc]][nc - dc[drc]] = v[r][c];
                v[r][c] = 0;

                r = nr - dr[drc];
                c = nc - dc[drc];
            }

            break;
        }
    }
}

void addBlock(vector<vector<int>>& v, int& r, int& c, int drc) {
    v[r + dr[drc]][c + dc[drc]] *= 2;
    v[r][c] = 0;

    r += dr[drc];
    c += dc[drc];

    pushBlock(v, r, c, drc);

    return;
}

void bt(int n, vector<vector<int>> v) {
    if (n == 5) {
        int m = 0;

        for (int i = 0; i < N; i++) {
            m = max(m, *max_element(v[i].begin(), v[i].end()));
        }

        if (m > answer) answer = m;        

        return;
    }

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp(v);
        vector<vector<int>> added(N, vector<int>(N));

        if (i == 0) {
            for (int ii = N - 2; ii >= 0; ii--) {
                for (int iii = 0; iii < N; iii++) {
                    int r = ii;
                    int c = iii;

                    pushBlock(temp, r, c, i);

                    if (r + dr[i] >= N || c + dc[i] >= N || r + dr[i] < 0 || c + dc[i] < 0) continue;
                    if (temp[r][c] == temp[r + dr[i]][c + dc[i]] && added[r + dr[i]][c + dc[i]] == 0) {
                        addBlock(temp, r, c, i);

                        added[r][c] = 1;
                    }
                }
            }
        }
        else if (i == 1) {
            for (int ii = 1; ii < N; ii++) {
                for (int iii = 0; iii < N; iii++) {
                    int r = ii;
                    int c = iii;

                    pushBlock(temp, r, c, i);

                    if (r + dr[i] >= N || c + dc[i] >= N || r + dr[i] < 0 || c + dc[i] < 0) continue;
                    if (temp[r][c] == temp[r + dr[i]][c + dc[i]] && added[r + dr[i]][c + dc[i]] == 0) {
                        addBlock(temp, r, c, i);

                        added[r][c] = 1;
                    }
                }
            }
        }
        else if (i == 2) {
            for (int iii = N - 2; iii >= 0; iii--) {
                for (int ii = 0; ii < N; ii++) {
                    int r = ii;
                    int c = iii;

                    pushBlock(temp, r, c, i);

                    if (r + dr[i] >= N || c + dc[i] >= N || r + dr[i] < 0 || c + dc[i] < 0) continue;
                    if (temp[r][c] == temp[r + dr[i]][c + dc[i]] && added[r + dr[i]][c + dc[i]] == 0) {
                        addBlock(temp, r, c, i);

                        added[r][c] = 1;
                    }
                }
            }
        }
        else if (i == 3) {
            for (int iii = 1; iii < N; iii++) {
                for (int ii = 0; ii < N; ii++) {
                    int r = ii;
                    int c = iii;

                    pushBlock(temp, r, c, i);

                    if (r + dr[i] >= N || c + dc[i] >= N || r + dr[i] < 0 || c + dc[i] < 0) continue;
                    if (temp[r][c] == temp[r + dr[i]][c + dc[i]] && added[r + dr[i]][c + dc[i]] == 0) {
                        addBlock(temp, r, c, i);

                        added[r][c] = 1;
                    }
                }
            }
        }

        bt(n + 1, temp);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;

    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < N; ii++) cin >> v[i][ii];
    }

    bt(0, v);

    cout << answer;
}