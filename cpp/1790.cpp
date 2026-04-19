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

    int N, k; cin >> N >> k;
    k--;

    int start = 1;
    int end = N;
    int degree = 1;

    while (degree * 9 * pow(10, degree - 1) <= k) {
        k -= degree * 9 * pow(10, degree - 1);
        start *= 10;

        degree++;
    }

    

    bool run = true;
    while (start <= end && k && run) {
        int temp = 8;
        while (temp) {
            if (degree * temp * pow(10, degree - 1) <= k) {
                k -= degree * temp * pow(10, degree - 1);
                start += temp * pow(10, degree - 1);
            }
            temp--;
        }

        for (int i = start; i < pow(10, degree); i++) {
            if (k < degree) {
                run = false;
                break;
            }

            k -= degree;
            start++;
        }
    }

    if (start > end) cout << -1;
    else cout << to_string(start)[k];
}