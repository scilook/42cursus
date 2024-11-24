#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.est", O_RDONLY);
	char *s;
	int i = 0;
	//for (char *s = get_next_line(fd); s != NULL; s = get_next_line(fd))
	for (char *s = get_next_line(fd); i < 10; s = get_next_line(fd))
	{
		printf("%s", s);
		free(s);
		i++;
	}
}