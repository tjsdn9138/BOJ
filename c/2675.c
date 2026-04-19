#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int T, R;
	char str[21];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %s", &R, str);
		for (int ii = 0; ii < strlen(str); ii++) {
			for (int iii = 0; iii < R; iii ++) {
				printf("%c", str[ii]);
			}
		}
		printf("\n");
	}

	return 0;
}