#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);

	int graph[100][100] = {0};
	for (int i = 0; i < K; i++) {
		int input[4];
		scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);

		for (int ii = input[0]; ii < input[2]; ii++) {
			for (int iii = input[1]; iii < input[3]; iii++) {
				graph[iii][ii] = 1;
			}
		}
	}

	int q[10000][2];
	int front = 0, rear = 0;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int answer[10000];
	int index = 0;

	for (int i = 0; i < M; i++) {
		for (int ii = 0; ii < N; ii++) {
			if (graph[i][ii] == 0) {
				graph[i][ii] = 1;
				q[rear][0] = ii;
				q[rear++][1] = i;

				int area = 1;
				while (front < rear) {
					int x = q[front][0];
					int y = q[front++][1];

					for (int iii = 0; iii < 4; iii++) {
						int nx = x + dx[iii];
						int ny = y + dy[iii];

						if (nx >= N || ny >= M || nx < 0 || ny < 0) continue;
						if (graph[ny][nx] == 1) continue;

						graph[ny][nx] = 1;
						area++;
						q[rear][0] = nx;
						q[rear++][1] = ny;
					}
				}

				answer[index++] = area;
			}
		}
	}

	for (int i = 0; i < index - 1; i++) {
		for (int ii = 0; ii < index - 1 - i; ii++) {
			if (answer[ii] > answer[ii + 1]) {
				int temp = answer[ii];
				answer[ii] = answer[ii + 1];
				answer[ii + 1] = temp;
			}
		}
	}

	printf("%d\n", index);
	for (int i = 0; i < index; i++) printf("%d ", answer[i]);

	return 0;
}