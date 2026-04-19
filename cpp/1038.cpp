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

int N;
int degree = 1;
int cur = -1;
bool run = true;

vector<int> v(100000);

void bt(int n) {
    if (n == degree) {
        cur++;

        if (cur == N) {
            for (int i = 0; i < n; i++) cout << v[i];

            run = false;
        }

        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (n > 0 && v[n - 1] <= i) continue;

        v[n] = i;

        bt(n + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

     cin >> N;

     while (run) {
         if (degree == 11) {
             cout << -1;

             return 0;
         }

         bt(0);

         degree++;
     }
}