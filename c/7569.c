#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int M, N, H;
	scanf("%d %d %d", &M, &N, &H);

	int q[1000000][3];
	int front = 0, rear = 0;

	int graph[101][101][101];
	for (int i = 0; i < H; i++) {
		for (int ii = 0; ii < N; ii++) {
			for (int iii = 0; iii < M; iii++) {
				scanf("%d", &graph[i][ii][iii]);
				if (graph[i][ii][iii] == 1) {
					q[rear][0] = iii;
					q[rear][1] = ii;
					q[rear++][2] = i;
				}
			}
		}
	}

	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	int count = 0;
	int cnt = 0;
	while (front < rear) {
		cnt = rear - front;

		int check = 0;
		for (int i = 0; i < cnt; i++) {
			int x = q[front][0];
			int y = q[front][1];
			int z = q[front++][2];

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx >= M || ny >= N || nz >= H || nx < 0 || ny < 0 || nz < 0) continue;
				if (graph[nz][ny][nx] == -1 || graph[nz][ny][nx] == 1) continue;

				graph[nz][ny][nx] = 1;
				q[rear][0] = nx;
				q[rear][1] = ny;
				q[rear++][2] = nz;
				check = 1;
			}
		}

		if (check == 1) count++;
	}
	
	for (int i = 0; i < H; i++) {
		for (int ii = 0; ii < N; ii++) {
			for (int iii = 0; iii < M; iii++) {
				if (graph[i][ii][iii] == 0) {
					printf("%d", -1);
					return 0;
				}
			}
		}
	}
	printf("%d", count);

	return 0;
}