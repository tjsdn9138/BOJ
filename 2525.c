#include <stdio.h>

int main(void)
{
	int h, m, c;
	scanf("%d %d %d", &h, &m, &c);

	m += c;
	while (m >= 60) {
		m -= 60;
		h += 1;
	}
	if (h >= 24)
		h -= 24;

	printf("%d %d", h, m);

	return 0;
}