#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[101];
	scanf("%s", str);
	int size, result;
	size = strlen(str);
	result = strlen(str);
	for (int i = 0; i < size - 1; i++) {
		if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			result -= 1;
		}
		else if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')) {
			result -= 1;
		}
		else if (str[i] == 'd' && str[i + 1] == '-') {
			result -= 1;
		}
		else if ((str[i] == 's' || str[i] == 'z') && str[i + 1] == '=') {
			result -= 1;
		}
		else if ((str[i] == 'l' || str[i] == 'n') && str[i + 1] == 'j') {
			result -= 1;
		}
	}
	printf("%d", result);

	return 0;
}