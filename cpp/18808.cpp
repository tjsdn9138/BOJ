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

vector<vector<int>> turn(vector<vector<int>> v, int &r, int &c) {
    vector<vector<int>> temp(c, vector<int>(r));

    for (int i = 0; i < r; i++) {
        for (int ii = 0; ii < c; ii++) {
            temp[ii][r - 1 - i] = v[i][ii];
        }
    }

    swap(r, c);
    
    return temp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;

    vector<vector<int>> v(N, vector<int>(M));

    for (int k = 0; k < K; k++) {
        int R, C; cin >> R >> C;

        vector<vector<int>> sticker(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int ii = 0; ii < C; ii++) cin >> sticker[i][ii];
        }

        int isused = 0;
        for (int t = 0; t < 4; t++) {

            for (int i = 0; i < N - R + 1; i++) {
                for (int ii = 0; ii < M - C + 1; ii++) {
                    int check = 0;

                    for (int iii = 0; iii < R; iii++) {
                        for (int iv = 0; iv < C; iv++) {
                            if (sticker[iii][iv] && v[i + iii][ii + iv]) {
                                check = 1;

                                break;
                            }
                        }

                        if (check) break;
                    }

                    if (check == 0) {
                        isused = 1;

                        for (int iii = 0; iii < R; iii++) {
                            for (int iv = 0; iv < C; iv++) {
                                if (sticker[iii][iv]) {
                                    v[i + iii][ii + iv] = 1;
                                }
                            }
                        }

                        break;
                    }
                }

                if (isused) break;
            }

            if (isused) break;
            else sticker = turn(sticker, R, C);
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int ii = 0; ii < M; ii++) {
            if (v[i][ii]) answer++;
        }
    }

    cout << answer;
}