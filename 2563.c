#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int arr[100][100] = { {0} }, T, x, y, result = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &x, &y);
		for (int ii = x; ii < x + 10; ii++) {
			for (int iii = y; iii < y + 10; iii++) {
				arr[ii][iii] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int ii = 0; ii < 100; ii++) {
			if (arr[i][ii] == 1) {
				result += 1;
			}
		}
	}
	printf("%d", result);

	return 0;
}