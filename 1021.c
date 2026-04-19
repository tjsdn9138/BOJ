#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void delete(Node** node) {
	Node* temp = (*node)->next;
	(*node)->next = temp->next;

	free(temp);
}

int main(void)
{
	int N, M, answer = 0;
	scanf("%d %d", &N, &M);

	Node* node = createNode(1);
	Node* temp = node;
	for (int i = 2; i <= N; i++) {
		Node* newNode = createNode(i);

		node->next = newNode;
		node = newNode;
	}
	node->next = temp;

	for (int i = 0; i < M; i++) {
		int value;
		scanf("%d", &value);

		int count = 0;
		while (node->next->data != value) {
			node = node->next;
			count++;
		}

		answer += count > N - count ? N - count : count;
		delete(&node);
		N--;
	}

	printf("%d", answer);

	return 0;
}