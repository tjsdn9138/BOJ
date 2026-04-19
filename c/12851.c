#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	int graph[300001] = { 0 };
	int q[1000000];
	int front = 0, rear = 0;

	q[rear++] = N;

	int count = -1, count2 = 0, cnt = 0, flag = 0;
	while (1) {
		cnt = rear - front;
		count++;

		for (int c = 0; c < cnt; c++) {
			int cur = q[front++];

			if (cur == K) {
				flag = 1;
				count2++;
			}

			if (cur > 0 && (graph[cur - 1] == 0 || graph[cur - 1] == count + 1)) {
				graph[cur - 1] = graph[cur] + 1;
				q[rear++] = cur - 1;
			}
			if (cur < K) {
				if (graph[cur + 1] == 0 || graph[cur + 1] == count + 1) {
					graph[cur + 1] = graph[cur] + 1;
					q[rear++] = cur + 1;
				}
				if (graph[cur * 2] == 0 || graph[cur * 2] == count + 1) {
					graph[cur * 2] = graph[cur] + 1;
					q[rear++] = cur * 2;
				}
			}
		}

		if (flag == 1) {
			printf("%d\n%d", count, count2);
			break;
		}
	}

	return 0;
}