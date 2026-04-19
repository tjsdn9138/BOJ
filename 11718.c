#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101];
	while (fgets(str, sizeof(str), stdin)) {
		printf("%s", str);
	}

	return 0;
}