#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

typedef struct egg {
	int hp;
	int weight;
} egg;

int N;
int answer = 0;
vector<egg> v(10);

void fcn(int n) {
	if (n == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].hp <= 0) temp++;
		}

		if (temp > answer) answer = temp;

		return;
	}

	int flag = 0;
	if (v[n].hp > 0) {
		for (int i = 0; i < N; i++) {
			if (i == n) continue;
			if (v[i].hp <= 0) continue;

			flag = 1;

			v[n].hp -= v[i].weight;
			v[i].hp -= v[n].weight;

			fcn(n + 1);

			v[n].hp += v[i].weight;
			v[i].hp += v[n].weight;
		}
	}

	if (flag == 0) fcn(n + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) cin >> v[i].hp >> v[i].weight;

	fcn(0);

	cout << answer;
}