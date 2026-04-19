#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, v, result = 0;
	scanf("%d", &N);
	int arr[100 + 1];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &v);

	for (int i = 0; i < N; i++) {
		if (v == arr[i]) {
			result += 1;
		}
	}
	printf("%d", result);

	return 0;
}