#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int fib[50][2];


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    fib[0][0] = 1; fib[0][1] = 0;
    fib[1][0] = 0; fib[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        fib[i][0] = fib[i - 2][0] + fib[i - 1][0];
        fib[i][1] = fib[i - 2][1] + fib[i - 1][1];
    }

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        cout << fib[n][0] << " " << fib[n][1] << "\n";
    }

	return 0;
}