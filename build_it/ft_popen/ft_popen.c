#include <unistd.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	//lets start with vars
	int fd[2];
	int ernum;
	pid_t process;

	if (!file || !argv || !type || !(type == 'r' || type == 'w'))
		return (-1);
	process = fork();
	if (pipe(fd) < 0 || process < 0)
		return (-1);
	if (process == 0)
	{
		if (!execvp(file, argv))
			return (-1);	
	}	
	return (0);
}
int main(int ac, char **av)
{
	ft_popen("ls", av, 'r');
} 
