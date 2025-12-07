#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CMD_NUM 5

int picoshell(char **cmds[])
{
    int i = 0;
    int j;
    while (cmds[i] != 0)
    {
		j = 0;
		while (cmds[i][j] != 0)
		{
			printf("CMD[%d]: %s\n", i, cmds[i][j]);
			j++;
		}
		printf("This is an args: %d\n", i);
		i++;
    }
	return 0; 
}

//from subject
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

