#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[1001];
	int n;
	scanf("%s", str);
	scanf("%d", &n);
	printf("%c", str[n - 1]);

	return 0;
}