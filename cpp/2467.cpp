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

    int N; cin >> N;

    int min = 2000000000;
    pair<int, int> minPair;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    for (int i = 0; i < N - 1; i++) {
        int part = v[i];

        int left = i + 1;
        int right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int hap = part + v[mid];
            if (abs(hap) < abs(min)) {
                min = hap;
                minPair = { part, v[mid]};
            }

            if (hap > 0) right = mid - 1;
            else if (hap < 0) left = mid + 1;
            else break;
        }
    }

    cout << minPair.first << " " << minPair.second;
}