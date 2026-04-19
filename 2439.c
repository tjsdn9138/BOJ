#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int iii = n - i; iii > 0; iii--)
			printf(" ");
		for (int ii = 0; ii < i; ii++)
			printf("*");
		printf("\n");
	}

	return 0;
}