#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[9], max = 0, max_i;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
			max_i = i;
		}
	}
	printf("%d \n%d", max, max_i + 1);

	return 0;
}