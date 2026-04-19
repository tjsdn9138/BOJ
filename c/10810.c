#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, start, end, k, arr[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &k);
		for (int ii = start - 1; ii <= end - 1; ii++) {
			arr[ii] = k;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}