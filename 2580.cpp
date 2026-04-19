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

vector<vector<int>> v(9, vector<int>(9));
vector<pair<int, int>> zero;
int cntZero = 0;
bool done = false;
vector<vector<pair<int, int>>> square(9);

bool row[9][10];
bool col[9][10];
bool sq[9][10];

void bt(int n) {
    if (done) return;

    if (n == cntZero) {
        for (int i = 0; i < 9; i++) {
            for (int ii = 0; ii < 9; ii++) cout << v[i][ii] << " ";
            cout << "\n";
        }

        done = true;
        return;
    }

    int r = zero[n].first;
    int c = zero[n].second;
    int num = (int)(r / 3) * 3 + c / 3;

    for (int i = 1; i <= 9; i++) {
        if (row[r][i] || col[c][i] || sq[num][i]) continue;

        row[r][i] = true;
        col[c][i] = true;
        sq[num][i] = true;
        v[r][c] = i;

        bt(n + 1);

        row[r][i] = false;
        col[c][i] = false;
        sq[num][i] = false;
        v[r][c] = 0;

        if (done) return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            cin >> v[i][ii];

            int num = (int)(i / 3) * 3 + ii / 3;
            row[i][v[i][ii]] = true;
            col[ii][v[i][ii]] = true;
            sq[num][v[i][ii]] = true;

            if (v[i][ii] == 0) {
                zero.push_back({ i, ii });
                cntZero++;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            int num = (int)(i / 3) * 3 + ii / 3;

            square[num].push_back({ i, ii });
        }
    }

    bt(0);
}