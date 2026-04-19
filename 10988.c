#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Pal(char str[], int size);

int main(void)
{
	char str[101];
	int n;
	scanf("%s", str);
	n = strlen(str);
	printf("%d", Pal(str, n));

	return 0;
}

int Pal(char str[], int size)
{
	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[size - 1 - i]) {
			return 0;
		}
	}
	return 1;
}