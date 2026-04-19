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

long long C(int N, int M) {
    long long result = 1;

    for (int i = 1; i <= N; i++) {
        result = result * (M + i) / i;

        if (result > 1000000000) return 1000000001;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    K--;

    if (C(N, M) <= K) cout << -1;
    else {
        while (N && M && K) {
            if (C(N - 1, M) <= K) {
                cout << 'z';
                K -= C(N - 1, M);
                M--;
            }
            else {
                cout << 'a';
                N--;
            }
        }

        for (int i = 0; i < N; i++) cout << 'a';
        for (int i = 0; i < M; i++) cout << 'z';
    }
}