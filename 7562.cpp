#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	int q[90000][2];
	int front, rear, count, cnt, temp, temp2, flag;

	int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
	int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

	for (int t = 0; t < T; t++) {
		front = 0, rear = 0, count = 0, cnt = 0, flag = 0;

		int graph[301][301] = { 0 };

		int I;
		scanf("%d", &I);

		scanf("%d %d", &temp, &temp2);
		q[rear][0] = temp;
		q[rear++][1] = temp2;
		graph[temp2][temp] = 1;

		int target[2] = { 0 };
		scanf("%d %d", &target[0], &target[1]);

		if (temp == target[0] && temp2 == target[1]) {
			printf("%d\n", 0);
			continue;
		}

		while (front < rear) {
			cnt = rear - front;
			count++;

			for (int c = 0; c < cnt; c++) {
				int x = q[front][0];
				int y = q[front++][1];

				for (int i = 0; i < 8; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx >= I || ny >= I || nx < 0 || ny < 0) continue;
					if (graph[ny][nx] == 1) continue;

					if (nx == target[0] && ny == target[1]) {
						flag = 1;
						printf("%d\n", count);
						break;
					}

					q[rear][0] = nx;
					q[rear++][1] = ny;
					graph[ny][nx] = 1;
				}
				if (flag == 1) break;
			}
			if (flag == 1) break;
		}
	}

	return 0;
}