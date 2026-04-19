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
	int size;
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
	q->size++;
}

cord pop(Queue* q) {
	if (isEmpty(q)) return;

	Node* cur = q->front;
	cord value = cur->data;
	q->front = cur->next;

	if (q->front == NULL) q->rear = NULL;
	else q->front->prev = NULL;
	free(cur);
	q->size--;

	return value;
}


int main(void)
{
	Queue q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	int n, m;
	int graph[1001][1001] = { 0 };
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int ii = 1; ii <= m; ii++) {
			scanf("%d", &graph[i][ii]);
			if (graph[i][ii] == 1) push(&q, (cord) { ii, i });
		}
	}

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	int count = 0;
	int cnt = q.size;
	int flag = 0;
	while (!isEmpty(&q)) {
		cord cur = pop(&q);
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx > m || ny > n || nx < 1 || ny < 1) continue;
			if (graph[ny][nx] != 0) continue;

			graph[ny][nx] = 1;
			push(&q, (cord) { nx, ny });
			flag = 1;
		}
		cnt--;

		if (cnt == 0) {
			cnt = q.size;
			if (flag) count++;
			flag = 0;
		}
	}

	int check = 0;
	for (int i = 1; i <= n; i++) {
		for (int ii = 1; ii <= m; ii++) {
			if (graph[i][ii] == 0) check = 1;
		}
	}

	if (check) printf("%d", -1);
	else printf("%d", count);

	return 0;
}