#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101];
	scanf("%s", str);
	for (int i = 0; i < 26; i++) {
		int k = 0;
		for (int ii = 0; ii < strlen(str); ii++) {
			if (str[ii] == ("%c", i + 97)) {
				printf("%d ", ii);
				k = 1;
				break;
			}
		}
		if (k == 0) {
			printf("%d ", -1);
		}
	}

	return 0;
}