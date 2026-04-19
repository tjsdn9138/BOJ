#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;

typedef struct shark {
	int r;
	int c;
	int speed;
	int dir;
	int size;
} shark;

int R, C, M;
vector<vector<int>> v(101, vector<int>(101));
vector<shark> sharks(10001);
vector<bool> isdied(10001);

int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, 1, -1 };

void move() {
	vector<tuple<int, int, int>> temp;

	for (int i = 1; i <= M; i++) {
		if (isdied[i]) continue;

		shark cur = sharks[i];
		v[cur.r][cur.c] = 0;

		for (int ii = 0; ii < cur.speed; ii++) {
			if (cur.r + dr[cur.dir] < 0 || cur.r + dr[cur.dir] >= R ||
				cur.c + dc[cur.dir] < 0 || cur.c + dc[cur.dir] >= C) {
				switch (cur.dir) {
				case 1:
					cur.dir = 2;
					break;
				case 2:
					cur.dir = 1;
					break;
				case 3:
					cur.dir = 4;
					break;
				case 4:
					cur.dir = 3;
					break;
				}
			}

			cur.r += dr[cur.dir];
			cur.c += dc[cur.dir];
		}
		sharks[i].r = cur.r;
		sharks[i].c = cur.c;
		sharks[i].dir = cur.dir;

		if (v[cur.r][cur.c]) temp.push_back({ i, cur.r, cur.c });
		else v[cur.r][cur.c] = i;
	}

	for (auto x : temp) {
		int num, row, col;
		tie(num, row, col) = x;

		if (v[row][col]) {
			if (sharks[num].size < sharks[v[row][col]].size) {
				isdied[num] = true;
			}
			else {
				isdied[v[row][col]] = true;
				v[row][col] = num;
			}
		}
		else v[row][col] = num;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++) {
		int row, col;
		cin >> row >> col >> sharks[i].speed >> sharks[i].dir >> sharks[i].size;

		row--;
		col--;
		sharks[i].r = row;
		sharks[i].c = col;

		if (sharks[i].dir == 1 || sharks[i].dir == 2) {
			sharks[i].speed %= 2 * R - 2;
		}
		else sharks[i].speed %= 2 * C - 2;

		v[row][col] = i;
	}

	int answer = 0;
	for (int ii = 0; ii < C; ii++) {
		for (int i = 0; i < R; i++) {
			if (v[i][ii]) {
				answer += sharks[v[i][ii]].size;
				isdied[v[i][ii]] = true;
				v[i][ii] = 0;

				break;
			}
		}

		move();
	}

	cout << answer;
}