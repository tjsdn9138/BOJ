#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int R, C;
	scanf("%d %d", &R, &C);

	int q_j[1000000][2];
	int front_j = 0, rear_j = 0;

	int q_f[1000000][2];
	int front_f = 0, rear_f = 0;

	char graph[1001][1001] = { 0 };
	for (int i = 0; i < R; i++) {
		char line[1001];
		scanf("%s", line);
		for (int ii = 0; ii < C; ii++) {
			graph[i][ii] = line[ii];
			if (graph[i][ii] == 'J') {
				q_j[rear_j][0] = ii;
				q_j[rear_j++][1] = i;
			}
			else if (graph[i][ii] == 'F') {
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
				if (graph[ny][nx] == '#' || graph[ny][nx] == 'F') continue;

				graph[ny][nx] = 'F';
				q_f[rear_f][0] = nx;
				q_f[rear_f++][1] = ny;
			}
		}

		int cnt_j = rear_j - front_j;
		if (cnt_j == 0) {
			printf("IMPOSSIBLE");
			return 0;
		}

		for (int t = 0; t < cnt_j; t++) {
			int x = q_j[front_j][0];
			int y = q_j[front_j++][1];

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= C || ny >= R || nx < 0 || ny < 0) {
					printf("%d", count);
					return 0;
				}
				if (graph[ny][nx] == '#' || graph[ny][nx] == 'F' || graph[ny][nx] == 'J') continue;

				q_j[rear_j][0] = nx;
				q_j[rear_j++][1] = ny;
				graph[ny][nx] = 'J';
			}
		}
	}

	return 0;
}