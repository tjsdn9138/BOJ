#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	int graph[300001] = { 0 };
	int q[200000];
	int front = 0, rear = 0;

	q[rear++] = N;
	while (1) {
		int cur = q[front++];
		if (cur == K) {
			printf("%d", graph[cur]);
			break;
		}

		if (cur > 0 && graph[cur - 1] == 0) {
			graph[cur - 1] = graph[cur] + 1;
			q[rear++] = cur - 1;
		}			
		if (cur < K) {
			if (graph[cur + 1] == 0) {
				graph[cur + 1] = graph[cur] + 1;
				q[rear++] = cur + 1;
			}
			if (graph[cur * 2] == 0) {
				graph[cur * 2] = graph[cur] + 1;
				q[rear++] = cur * 2;
			}
		}
	}

	return 0;
}