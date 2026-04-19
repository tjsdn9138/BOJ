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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        int x, y; cin >> x >> y;

        int dis = y - x;

        int move = 1;
        int answer = 0;
        while (dis) {
            if (dis < move * 2) {
                if (dis <= move) answer++;
                else answer += 2;

                break;
            }
            else {
                dis -= move * 2;
                answer += 2;
                move++;
            }
        }

        cout << answer << "\n";
    }
}