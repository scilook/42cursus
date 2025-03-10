#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("test", O_RDONLY);
	char *a = get_next_line(fd);

	printf("%s\n", a);
	free(a);
}