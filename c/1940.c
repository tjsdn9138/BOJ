#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, answer = 0;
	int arr[15001] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < N - 1; i++) {
		for (int ii = i + 1; ii < N; ii++) {
			if (arr[i] + arr[ii] == M) answer++;
		}
	}

	printf("%d", answer);

	return 0;
}