#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	int N, M, temp;
	int arr[100][100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			scanf("%d", &arr[i][ii]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			scanf("%d", &temp);
			arr[i][ii] += temp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < M; ii++) {
			printf("%d ", arr[i][ii]);
		}
		printf("\n");
	}

	return 0;
}