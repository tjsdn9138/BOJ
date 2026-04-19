#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d \n", a * (b % 10));
	printf("%d \n", a * (b % 100 / 10));
	printf("%d \n", a * (b / 100));
	printf("%d \n", a * b);

	return 0;
}