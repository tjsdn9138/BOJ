#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int N;
	scanf("%d", &N);

	char graph[111][111] = { 0 };
	char graph2[111][111] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%s", graph[i]);
		for (int ii = 0; ii < N; ii++) {
			graph2[i][ii] = graph[i][ii];
		}
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int q[1000000][2];
	int front = 0, rear = 0;

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			if (graph[i][ii] != 0) {
				front = 0, rear = 0;
				q[rear][0] = ii;
				q[rear++][1] = i;
				char color = graph[i][ii];
				graph[i][ii] = 0;
				count++;

				while (front < rear) {
					int x = q[front][0];
					int y = q[front++][1];

					for (int iii = 0; iii < 4; iii++) {
						int nx = x + dx[iii];
						int ny = y + dy[iii];

						if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
						if (graph[ny][nx] != color) continue;

						q[rear][0] = nx;
						q[rear++][1] = ny;
						graph[ny][nx] = 0;
					}
				}
			}
		}
	}
	printf("%d ", count);

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			if (graph2[i][ii] == 'G') graph2[i][ii] = 'R';
		}
	}

	count = 0;
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N; ii++) {
			if (graph2[i][ii]) {
				front = 0, rear = 0;
				q[rear][0] = ii;
				q[rear++][1] = i;
				char color = graph2[i][ii];
				graph2[i][ii] = 0;
				count++;

				while (front < rear) {
					int x = q[front][0];
					int y = q[front++][1];

					for (int iii = 0; iii < 4; iii++) {
						int nx = x + dx[iii];
						int ny = y + dy[iii];

						if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
						if (graph2[ny][nx] != color) continue;

						q[rear][0] = nx;
						q[rear++][1] = ny;
						graph2[ny][nx] = 0;
					}
				}
			}
		}
	}
	printf("%d", count);

	return 0;
}