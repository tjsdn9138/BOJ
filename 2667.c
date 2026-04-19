#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	int N;	scanf("%d",&N);

	int graph[100][100] = { 0 };

	for (int i = 0; i < N; i++) {

		char input[100];

		scanf("%s", input);

		for (int ii = 0; ii < N; ii++) {

			graph[i][ii] = input[ii] - '0';

		}

	}

	

	int q[10000][2];

	int front = 0, rear = 0;

	int dx[4] = { 1, -1, 0, 0 };

	int dy[4] = { 0, 0, 1, -1 };

	int answer[10000];

	int index = 0;

	for (int i = 0; i < N; i++) {

		for (int ii = 0; ii < N; ii++) {

			if (graph[i][ii] == 1) {

				graph[i][ii] = 0;

				q[rear][0] = ii;

				q[rear++][1] = i;

				int area = 1;

				while (front < rear) {

					int x = q[front][0];

					int y = q[front++][1];

					for (int iii = 0; iii < 4; iii++) {

						int nx = x + dx[iii];

						int ny = y + dy[iii];

						if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;

						if (graph[ny][nx] == 0) continue;

						graph[ny][nx] = 0;

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

	for (int i = 0; i < index; i++) printf("%d\n", answer[i]);

	return 0;

}