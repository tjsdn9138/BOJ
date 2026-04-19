#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

float dict(char str[]);

int main(void)
{
	float total = 0, Total = 0, score;
	char name[51], str[3];
	while (scanf("%s %f %s", name, &score, str) != EOF) {
		if (strcmp(str, "P") != 0) {
			total += score;
			Total += score * dict(str);
		}
	}
	printf("%.6f", Total / total);

	return 0;
}

float dict(char str[])
{
	if (strcmp(str, "A+") == 0) return 4.5;
	else if (strcmp(str, "A0") == 0) return 4.0;
	else if (strcmp(str, "B+") == 0) return 3.5;
	else if (strcmp(str, "B0") == 0) return 3.0;
	else if (strcmp(str, "C+") == 0) return 2.5;
	else if (strcmp(str, "C0") == 0) return 2.0;
	else if (strcmp(str, "D+") == 0) return 1.5;
	else if (strcmp(str, "D0") == 0) return 1.0;
	else if (strcmp(str, "F") == 0) return 0.0;
}