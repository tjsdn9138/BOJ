#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int sum = 2, X, mom = 1, son = 1;
	scanf("%d", &X);
	if (X == 1) {
		printf("1/1");
	}
	else {
		for (int i = 0; i < X - 1; i++) {
			if (sum % 2 == 0) {
				if (son == 1) {
					mom++;
					sum++;
				}
				else {
					mom++;
					son--;
				}
			}
			else {
				if (mom == 1) {
					son++;
					sum++;
				}
				else {
					mom--;
					son++;
				}
			}
		}
		printf("%d/%d", son, mom);
	}
	


	return 0;
}