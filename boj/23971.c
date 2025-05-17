#include <stdio.h>
#include <math.h>

int main(void)
{
	int	arr[4];
	int	cnt;

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", arr + i);
	}
	cnt = 0;
	for (int i = 0; i < arr[0]; i = i + arr[2] + 1)
	{
		cnt += (arr[1] - 1) / (arr[3] + 1) + 1;
		//cnt += (int)ceil(arr[1]/(arr[3] + 1) + 1);
	}
	printf("%d\n", cnt);
	return (0);
}
