#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	char arr[5][16];
	for (int i = 0; i < 5; i++) {
		for (int ii = 0; ii < 16; ii++) {
			arr[i][ii] = ' ';
		}
	}
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < 16; i++) {
		for (int ii = 0; ii < 5; ii++) {
			if ((arr[ii][i] != '\0') && (arr[ii][i] != ' ')) {
				printf("%c", arr[ii][i]);
			}
		}
	}

	return 0;
}