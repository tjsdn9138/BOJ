#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, n, temp = 0, answer = 0;
	int arr[1001];
	scanf("%d", &N);
	n = N;
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int ii = 0; ii < N - i - 1; ii++) {
			if (arr[ii] > arr[ii + 1]) {
				temp = arr[ii];
				arr[ii] = arr[ii + 1];
				arr[ii + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		answer += arr[i] * n;
		n--;
	}

	printf("%d", answer);

	return 0;
}