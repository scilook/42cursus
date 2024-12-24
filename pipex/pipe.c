#include "pipex.h"
#include "stdio.h"

int	pipex(int fdin)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd); //fd[0]과 fd[1]로 지정된 파이프를 생성합니다.
	pid = fork(); //fork함수를 통해 정보를 주고받을 2개의 프로세스 객체를 생성합니다.

	if(pid == 0)
	{

	}
	else
	{
	waitpid(pid, NULL, 0);
		printf("%s\n", getpid());
	}
	exit(0);
}