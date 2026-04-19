#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	int graph[1000000] = { 0 };

	int q[1000000];
	int front = 0, rear = 0;

	q[rear++] = S;
	graph[S] = 1;

	int cnt;
	int count = -1;
	while (front < rear) {
		cnt = rear - front;
		count++;

		for (int c = 0; c < cnt; c++) {
			int x = q[front++];

			if (x == G) {
				printf("%d", count);
				return 0;
			}
			
			int ux = x + U;
			if (ux <= F && graph[ux] == 0) {
				q[rear++] = ux;
				graph[ux] = 1;
			}
			
			
			int dx = x - D;
			if (dx > 0 && graph[dx] == 0) {
				q[rear++] = dx;
				graph[dx] = 1;
			}
		}
	}

	printf("use the stairs");
	
	return 0;
}