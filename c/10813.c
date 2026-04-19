#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, k, j, temp = 0, arr[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &k, &j);
		temp = arr[k - 1];
		arr[k - 1] = arr[j - 1];
		arr[j - 1] = temp;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}