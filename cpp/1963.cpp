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

vector<bool> era(10000, true);

void fcn(int start, int end) {
    queue<int> q;
    q.push(start);

    vector<bool> visited(10000);
    visited[start] = true;

    int level = 0;
    while (!q.empty()) {
        int S = q.size();

        for (int s = 0; s < S; s++) {
            int current = q.front(); q.pop();

            if (current == end) {
                cout << level << "\n";

                return;
            }

            string cur = to_string(current);

            for (int i = 0; i < 4; i++) {
                for (char ii = '0'; ii <= '9'; ii++) {
                    if (i == 0 && ii == '0') continue;
                    if (cur[i] == ii) continue;

                    string temp = cur;
                    temp[i] = ii;

                    int nxt = stoi(temp);
                    if (era[nxt] && visited[nxt] == false) {
                        q.push(nxt);
                        visited[nxt] = true;
                    }
                }
            }
        }

        level++;
    }

    cout << "Impossible" << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    era[0] = era[1] = false;
    for (int i = 2; i <= 100; i++) {
        for (int ii = i * i; ii <= 9999; ii += i) {
            era[ii] = false;
        }
    }

    for (int t = 0; t < T; t++) {
        int start, end; cin >> start >> end;

        fcn(start, end);
    }
}