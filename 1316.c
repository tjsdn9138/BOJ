#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int count(int n, char str[], int size);

int main(void)
{
	int N, result = 0;
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		char str[101];
		int size;
		scanf("%s", str);
		size = strlen(str);
		for (int i = 0; i < size; i++) {
			int start = 0, end = 0, cnt = 0;
			cnt = count(str[i], str, size);
			for (int ii = 0; ii < size; ii++) {
				if (str[ii] == str[i]) {
					start = ii;
					break;
				}
			}
			for (int iii = size - 1; iii >= 0; iii--) {
				if (str[iii] == str[i]) {
					end = iii;
					break;
				}
			}
			if ((end - start) != cnt - 1) {
				result += 1;
				break;
			}
		}
	}
	printf("%d", N - result);

	return 0;
}

int count(int n, char str[], int size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		if (n == str[i]) {
			result += 1;
		}
	}
	return result;
}