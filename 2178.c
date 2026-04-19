#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (a) > (b) ? (b) : (a)

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
	int graph[101][101] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		char line[102];
		scanf("%s", line);
		for (int ii = 1; ii <= m; ii++) {
			graph[i][ii] = line[ii - 1] - '0';
		}
	}

	Queue q;
	q.front = NULL;
	q.rear = NULL;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	cord temp = { 1,1 };
	push(&q, temp);

	while (!isEmpty(&q)) {
		cord cur = pop(&q);
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > n || ny > m || nx < 1 || ny < 1) continue;
			if (graph[nx][ny] != 1) continue;

			graph[nx][ny] = graph[x][y] + 1;
			cord cur = { nx, ny };
			push(&q, cur);
		}
	}

	printf("%d", graph[n][m]);

	return 0;
}