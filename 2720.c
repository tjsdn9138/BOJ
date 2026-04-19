#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		int money, result[4] = { 0 };
		scanf("%d", &money);
		result[0] = (money / 25);
		money %= 25;
		result[1] = (money / 10);
		money %= 10;
		result[2] = (money / 5);
		money %= 5;
		result[3] = money;

		for (int i = 0; i < 4; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	return 0;
}