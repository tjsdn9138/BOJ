#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int x;
	int y;
} cord;

typedef struct Node {
	cord data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

Node* createNode(cord value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

int isEmpty(Queue* q) { return q->rear == NULL; }

void push(Queue* q, cord value) {
	Node* newNode = createNode(value);

	if (isEmpty(q)) (q->front) = (q->rear) = newNode;
	else {
		newNode->prev = q->rear;
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

cord pop(Queue* q) {
	if (isEmpty(q)) return;

	Node* cur = q->front;
	cord value = cur->data;
	q->front = cur->next;

	if (q->front == NULL) q->rear = NULL;
	else q->front->prev = NULL;
	free(cur);

	return value;
}


int main(void)
{
	int n, m;
	int graph[501][501] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int ii = 1; ii <= m; ii++) {
			scanf("%d", &graph[i][ii]);
		}
	}

	Queue q;
	q.front = NULL;
	q.rear = NULL;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	int max = 0;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int ii = 1; ii <= m; ii++) {
			if (graph[i][ii]) {
				int x = ii;
				int y = i;

				push(&q, (cord){ x, y });
				graph[i][ii] = 0;
				int cnt = 1;
				while (!isEmpty(&q)) {
					cord cur = pop(&q);

					for (int iii = 0; iii < 4; iii++) {
						int nx = cur.x + dx[iii];
						int ny = cur.y + dy[iii];

						if (nx > m || ny > n || nx < 1 || ny < 1) continue;
						if (graph[ny][nx] == 0) continue;

						push(&q, (cord){ nx, ny });
						graph[ny][nx] = 0;
						cnt++;
					}
				}				
				if (cnt > max) max = cnt;
				count++;
			}
		}
	}

	printf("%d\n%d", count, max);

	return 0;
}