#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fcn();

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		fcn();
		printf("\n");
	}

	return 0;
}

void fcn() {
	int R, C;
	scanf("%d %d", &C, &R);

	int q_j[10000000][2];
	int front_j = 0, rear_j = 0;

	int q_f[10000000][2];
	int front_f = 0, rear_f = 0;

	char graph[1001][1001] = { 0 };
	for (int i = 0; i < R; i++) {
		char line[1001];
		scanf("%s", line);
		for (int ii = 0; ii < C; ii++) {
			graph[i][ii] = line[ii];
			if (graph[i][ii] == '@') {
				q_j[rear_j][0] = ii;
				q_j[rear_j++][1] = i;
			}
			else if (graph[i][ii] == '*') {
				q_f[rear_f][0] = ii;
				q_f[rear_f++][1] = i;
			}
		}
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int count = 0;
	while (1) {
		count++;

		int cnt_f = rear_f - front_f;
		for (int t = 0; t < cnt_f; t++) {
			int x = q_f[front_f][0];
			int y = q_f[front_f++][1];

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= C || ny >= R || nx < 0 || ny < 0) continue;
				if (graph[ny][nx] == '#' || graph[ny][nx] == '*') continue;

				graph[ny][nx] = '*';
				q_f[rear_f][0] = nx;
				q_f[rear_f++][1] = ny;
			}
		}

		int cnt_j = rear_j - front_j;
		if (cnt_j == 0) {
			printf("IMPOSSIBLE");
			return;
		}

		for (int t = 0; t < cnt_j; t++) {
			int x = q_j[front_j][0];
			int y = q_j[front_j++][1];

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= C || ny >= R || nx < 0 || ny < 0) {
					printf("%d", count);
					return;
				}
				if (graph[ny][nx] == '#' || graph[ny][nx] == '*' || graph[ny][nx] == '@') continue;

				q_j[rear_j][0] = nx;
				q_j[rear_j++][1] = ny;
				graph[ny][nx] = '@';
			}
		}
	}

	return;
}