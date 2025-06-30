#include "minishell.h"

int main(void)
{
	char *line;
	while(1)
	{
		line = readline(getenv("PS1"));
		printf("Result : %s\n", line); //건환님 함수
		char **argv = ft_split(line, ' ');
		
		add_history(line);
		free(line);

	}
	return(0);
}