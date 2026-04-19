#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define max 300000


int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	int graph[max];
	for (int i = 0; i < max; i++) graph[i] = -1;
	int q[MAX];
	int front = 0, rear = 0;

	q[rear++] = N;
	graph[N] = 0;
	while (1) {
		int cur = q[front];
		front = (front + 1) % MAX;

		if (cur == K) {
			printf("%d", graph[cur]);
			break;
		}

		if (graph[cur * 2] == -1 && cur * 2 < max) {
			graph[cur * 2] = graph[cur];
			front = (front - 1 + MAX) % MAX;
			q[front] = cur * 2;
		}
		if ((graph[cur - 1] == -1) && cur > 0) {
			graph[cur - 1] = graph[cur] + 1;
			q[rear] = cur - 1;
			rear = (rear + 1) % MAX;
		}
		if (graph[cur + 1] == -1 && cur < K) {
			graph[cur + 1] = graph[cur] + 1; 
			q[rear] = cur + 1;
			rear = (rear + 1) % MAX;
		}			
	}

	return 0;
}