#include "msh.h"

#include "carbon.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#include "private/prv_interpreter.h"

void	sigint_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sigint_handler);
	printf("\n");
	msh_prompt("msh$ ");
}

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;
	// t_prog	*prog;

	signal(SIGINT, sigint_handler);
	(void)argc;
	(void)argv;
	msh_env(envp);
	status = 0;
	while (!status)
	{
		line = msh_prompt("msh$ ");
		if (str_cmp(line, "exit") == 0)
			msh_exit(0, "exit");
		else
		{
			printf("cmd: %s\n", line);
		}

		// msh_parse(line, &prog);
		// msh_interpreter(prog); // will segfault until parser is done
		// while (msh_parse(NULL, &prog) > 0)
		// {
		// 	msh_interpreter(prog);
		// }
	}





	// int	p[2];
	// printf("pipe ret: %i\n", pipe(p));
	// char *cmd[] = {"ls", "-la", NULL};
	// t_prog testprog = {};
	// testprog.argv = cmd;
	// testprog.in_fd = 0;
	// testprog.out_fd = p[1];
	// msh_interpreter(&testprog);
	// char *cmd2[] = {"cat", NULL};
	// t_prog testprog2 = {0};
	// testprog2.argv = cmd2;
	// testprog2.in_fd = p[0];
	// testprog2.out_fd = 1;
	// msh_interpreter(&testprog2);
	return (0);
}
