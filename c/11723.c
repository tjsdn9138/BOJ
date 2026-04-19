#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int M, n, arr[21] = { 0, };
	char order[10] = { 0, };

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%s", order);

		if (strcmp(order, "add") == 0) {
			scanf("%d", &n);
			arr[n] = 1;
		}

		if (strcmp(order, "remove") == 0) {
			scanf("%d", &n);
			arr[n] = 0;
		}

		if (strcmp(order, "check") == 0) {
			scanf("%d", &n);
			if (arr[n]) printf("%d\n", 1);
			else printf("%d\n", 0);
		}

		if (strcmp(order, "toggle") == 0) {
			scanf("%d", &n);
			if (arr[n]) arr[n] = 0;
			else arr[n] = 1;
		}

		if (strcmp(order, "all") == 0) {
			for (int ii = 1; ii <= 20; ii++) {	
				arr[ii] = 1;
			}
		}

		if (strcmp(order, "empty") == 0) {
			for (int ii = 1; ii <= 20; ii++) {
				arr[ii] = 0;
			}
		}
	}

	return 0;
}