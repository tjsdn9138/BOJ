#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char n[]);

int main(void)
{
	char A[4], B[4];
	scanf("%s %s", A, B);
	reverse(A);
	reverse(B);
	printf("%d", atoi(A) > atoi(B) ? atoi(A) : atoi(B));

	return 0;
}

void reverse(char n[])
{
	int size = strlen(n);
	char temp;
	for (int i = 0; i < size / 2; i++) {
		temp = n[i];
		n[i] = n[size - 1 - i];
		n[size - 1 - i] = temp;
	}
}