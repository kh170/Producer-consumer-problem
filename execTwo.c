#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int pipefd[2],status,done=0;
	pid_t cpid;

	pipe(pipefd);
	
	cpid = fork();

	if (cpid==0)
	{  
		char*  args[]={argv[1],
			NULL
		};
		close(pipefd[0]);
		dup2(pipefd[1],STDOUT_FILENO);
		execv(args[0],args);
	}

	cpid = fork();
	if (cpid==0)
	{
		char* argm[]={argv[2],
			NULL
		};
		close(pipefd[1]);
		dup2(pipefd[0],STDIN_FILENO);
		execv(argm[0],argm);
	}

	close(pipefd[0]);
	close(pipefd[1]);


	waitpid(-1,&status,0);
	waitpid(-1,&status,0);
}
		

