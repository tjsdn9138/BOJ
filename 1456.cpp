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

    long long A, B; cin >> A >> B;
    int answer = 0;

    vector<bool> era(sqrt(B) + 1, true);
    era[0] = false; era[1] = false;

    for (long long i = 2; i <= sqrt(sqrt(B)); i++) {
        for (int ii = i * i; ii <= sqrt(B); ii += i) era[ii] = false;
    }

    for (long long i = 2; i <= sqrt(B); i++) {
        if (era[i] == false) continue;

        int degree = 2;
        while (true) {
            if (pow(i, degree) > B) break;

            if (pow(i, degree) >= A) answer++;

            degree++;
        }
    }

    cout << answer;
}