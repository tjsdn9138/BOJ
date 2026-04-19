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

    int N, P, S; cin >> N >> P >> S;

    for (int s = 0; s < S; s++) {
        int m; cin >> m;

        bool flag = false;
        for (int i = 0; i < m; i++) {
            int card; cin >> card;
            
            if (card == P) flag = true;
        }

        if (flag) cout << "KEEP\n";
        else cout << "REMOVE\n";
    }
}