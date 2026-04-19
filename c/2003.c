#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, temp = 0, answer = 0;
	int arr[10001];

	scanf("%d %d", &N, &M);
	scanf("%d", &arr[0]);
	for (int i = 1; i < N; i++) {
		scanf("%d", &temp);
		arr[i] = arr[i - 1] + temp;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] == M) answer++;

		for (int ii = i + 1; ii < N; ii++) {
			if (arr[ii] - arr[i] == M) answer++;
		}
	}

	printf("%d", answer);


	return 0;
}