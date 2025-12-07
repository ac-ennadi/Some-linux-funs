#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
	int n_pid;
	// char **args = cmds[0];

	n_pid = fork();
	// in the child pross.. fork retrun 0 || 
	if (n_pid == 0)
	{
		wait(n_pid);
	}
	//fork < 0 mean we are in the parent pross.. 
	else
		printf("On Parent Pross.. n_pid value: %d\n getpid: %d\n", n_pid, getpid());
	return 0; 
}

int	main(int argc, char **argv)
{
	int	cmds_size = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	char ***cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return 1;
	}
	cmds[cmds_size] = NULL; //need confirmation for this line
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	}
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}
