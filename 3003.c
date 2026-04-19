#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	int arr[7] = { 1,1,2,2,2,8 }, n;
	for (int i = 0; i < 6; i++) {
		scanf("%d", &n);
		printf("%d ", arr[i] - n);
	}

	return 0;
}