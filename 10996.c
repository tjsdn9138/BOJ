#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int ii = 0; ii < (n - 1) / 2; ii++) printf("* ");
		printf("*\n");

		for (int ii = 0; ii < n / 2; ii++) printf(" *");
		printf("\n");
	}

	return 0;
}