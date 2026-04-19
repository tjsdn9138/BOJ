#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int up, down, total, day;
	scanf("%d%d%d", &up, &down, &total);
	day = up - down;
	total -= up;
	if (total % day == 0) {
		printf("%d", total / day + 1);
	}
	else {
		printf("%d", total / day + 2);
	}

	return 0;
}