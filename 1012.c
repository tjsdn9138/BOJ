#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

int main(void) {

	int T, M, N, K;	scanf("%d", &T);

	for (int t = 0; t < T; t++) {

		scanf("%d %d %d", &M, &N, &K);

		int** graph;

		graph = (int**)malloc(sizeof(int*) * N);

		for (int i = 0; i < N; i++) {

			graph[i] = (int*)calloc(M, sizeof(int));

		}

		for (int i = 0; i < K; i++) {

			int tx, ty;

			scanf("%d %d", &tx, &ty);

			graph[ty][tx] = 1;

		}

		int q[200000][2];

		int front = 0, rear = 0;

		int dx[4] = { 1, -1, 0, 0 };

		int dy[4] = { 0, 0, 1, -1 };

		int count = 0;

		for (int i = 0; i < N; i++) {

			for (int ii = 0; ii < M; ii++) {

				if (graph[i][ii] == 1) {

					graph[i][ii] = 0;

					q[rear][0] = ii;

					q[rear++][1] = i;

					count++;

					while (front < rear) {

						int x = q[front][0];

						int y = q[front++][1];

						for (int iii = 0; iii < 4; iii++) {

							int nx = x + dx[iii];

							int ny = y + dy[iii];

							if (nx >= M || ny >= N || nx < 0 || ny < 0) continue;

							if (graph[ny][nx] == 0) continue;

							graph[ny][nx] = 0;

							q[rear][0] = nx;

							q[rear++][1] = ny;

						}

					}

				}

			}

		}

		printf("%d\n", count);

	}

	return 0;

}