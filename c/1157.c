#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void upper(char n[], int size);

int main(void)
{
	char str[1000001];
	int alpha[26] = { 0 };
	int max = 0, k = 0, size = 0;
	scanf("%s", str);
	size = strlen(str);
	upper(str, size);
	for (int i = 0; i < size; i++) {
		alpha[str[i] - 'A'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > alpha[max]) {
			max = i;
			k = 1;
		}
		else if (alpha[i] == alpha[max]) {
			k += 1;
		}
	}
	if (k > 1) {
		printf("?");
	}
	else {
		printf("%c", max + 'A');
	}

	return 0;
}

void upper(char n[], int size)
{
	for (int i = 0; i < size; i++) {
		if (n[i] >= 'a') {
			n[i] -= 32;
		}
	}
}