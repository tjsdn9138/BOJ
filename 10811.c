#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, k, j, temp = 0, arr[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++){
		scanf("%d %d", &j, &k);
		int left = j - 1;
		int right = k - 1;
		while (left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}