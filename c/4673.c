#include <stdio.h>

int main(void)
{
	int flag, sum, temp;

	for (int i = 1; i <= 10000; i++) {
		flag = 0;

		for (int ii = 1; ii < i; ii++) {
			sum = ii;
			temp = ii;

			while (temp > 0) {
				sum += temp % 10;
				temp /= 10;
			}
			
			if (sum == i) {
				flag = 1;
				break;
			}

		}

		if (flag == 0) printf("%d\n", i);
	}

	return 0;
}