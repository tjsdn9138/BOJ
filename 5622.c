#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int result = 0, arr[27] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	char n[16];
	scanf("%s", n);
	for (int i = 0; i < strlen(n); i++) {
		result += arr[n[i] - 'A'];
	}
	printf("%d", result);

	return 0;
}