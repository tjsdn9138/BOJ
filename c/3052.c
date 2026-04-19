#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int k, n = 0, result = 0;
	int arr[42] = {0, };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		k = n % 42;
		arr[k] += 1;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0) {
			result += 1;
		}
	}
	printf("%d", result);

	return 0;
}