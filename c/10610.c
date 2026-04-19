#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

int main(void)

{

	int size, count[10] = { 0 };	char N[100001];

	scanf("%s", N);

	size = strlen(N);

	int temp, index = 0, total = 0;

	while (1) {

		if (index > size - 1) break;

		temp = N[index++] - '0';

		count[temp]++;

		total += temp;

	}

	if (!(count[0] && total % 3 == 0)) printf("%d", -1);

	else {

		for (int i = 9; i >= 0; i--) {

			for (int ii = 0; ii < count[i]; ii++) printf("%d", i);

		}

	}

	

	return 0;

}