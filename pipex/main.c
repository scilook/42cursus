#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	argv++;
	if(argc > 0)
		execve(seek_path(argv[0], envp), argv, envp);
}