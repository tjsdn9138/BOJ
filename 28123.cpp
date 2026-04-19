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
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	long long n, k, x; cin >> n >> k >> x;
  
    long long answer = n - (k * 3 - 1);

    if (x == 1) cout << answer + 2;
    else if (x <= 4) cout << answer + 1;
    else cout << answer;
}