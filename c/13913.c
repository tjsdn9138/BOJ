#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	if (N == K) {
		printf("%d\n%d", 0, N);
		return 0;
	}

	int graph[300000] = { 0 };
	int path[300000];
	for (int i = 0; i < 300000; i++) path[i] = -1;
	int q[200000];
	int front = 0, rear = 0;

	q[rear++] = N;
	while (1) {
		int cur = q[front++];
		if (cur == K) {
			printf("%d\n", graph[cur]);
			break;
		}

		if (cur > 0 && graph[cur - 1] == 0) {
			graph[cur - 1] = graph[cur] + 1;
			q[rear++] = cur - 1;
			path[cur - 1] = cur;
		}
		if (cur < K) {
			if (graph[cur + 1] == 0) {
				graph[cur + 1] = graph[cur] + 1;
				q[rear++] = cur + 1;
				path[cur + 1] = cur;
			}
			if (graph[cur * 2] == 0) {
				graph[cur * 2] = graph[cur] + 1;
				q[rear++] = cur * 2;
				path[cur * 2] = cur;
			}
		}
	}

	int s[30000];
	int index = -1;
	int num = K;
	while (1) {
		s[++index] = num;
		num = path[num];

		if (num == N) {
			s[++index] = num;
			break;
		}
	}

	for (int i = index; i >= 0; i--) printf("%d ", s[i]);

	return 0;
}