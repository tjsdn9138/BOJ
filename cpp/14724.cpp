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

    int N; cin >> N;
    vector<string> dong = { "PROBRAIN", "GROW", "ARGOS", "ADMIN",
        "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
    vector<int> hap(9);

    int mx = 0;
    for (int i = 0; i < 9; i++) {
        int total = 0;
        
        for (int ii = 0; ii < N; ii++) {
            int input;
            cin >> input;

            total = max(total, input);
        }

        hap[i] = total;

        if (hap[i] > hap[mx]) mx = i;
    }

    cout << dong[mx];
}