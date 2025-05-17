#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int diff;
	int d1;
	int d2;

	scanf("%d\n%d", &d1, &d2);
	diff = d2 - d1;
	printf("%d\n", diff >= 0 ? diff : diff + 24);
	return (0);
}