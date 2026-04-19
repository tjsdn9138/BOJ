#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1001];
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", str);
		printf("%c%c\n", str[0], str[strlen(str) - 1]);
	}

	return 0;
}