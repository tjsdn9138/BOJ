#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[1000002];
	fgets(str, sizeof(str), stdin);
	int result = 0;
	if (str[0] >= 'A') {
		result = 1;
	}
	for (int i = 1; str[i] > '\0'; i++) {
		if (str[i - 1] == ' ' && str[i] >= 'A') {
			result++;
		}
	}
	printf("%d", result);

	return 0;
}