#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* prev;
	struct Node* next;
} Node;

Node* createNode(char value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void insert(Node** node, char value) {
	Node* newNode = createNode(value);

	if ((*node)->next != NULL) {
		(*node)->next->prev = newNode;
		newNode->next = (*node)->next;
	}

	(*node)->next = newNode;
	newNode->prev = (*node);

	*node = newNode;
}

void delete(Node** node) {
	if ((*node)->prev == NULL) return;

	if ((*node)->next != NULL) (*node)->next->prev = (*node)->prev;
	(*node)->prev->next = (*node)->next;

	*node = (*node)->prev;

	return;
}

int main(void)
{
	char input[100001] = { 0 };
	scanf("%s", input);

	Node* node = createNode(NULL);

	int index = 0;
	while (input[index]) {
		insert(&node, input[index++]);
	}

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char order;
		scanf(" %c", &order);

		if (order == 'L') {
			if (node->prev != NULL) node = node->prev;
		}
		else if (order == 'D') {
			if (node->next != NULL) node = node->next;
		}
		else if (order == 'B') {
			delete(&node);
		}
		else if (order == 'P') {
			char value;
			scanf(" %c", &value);
			insert(&node, value);
		}
	}

	while (node->prev != NULL) node = node->prev;
	node = node->next;

	while (1) {
		printf("%c", node->data);

		if (node->next != NULL) node = node->next;
		else break;
	}
	
	return 0;
}