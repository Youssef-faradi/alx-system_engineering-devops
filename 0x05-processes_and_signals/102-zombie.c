#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - Hangs parent process running
 *
 * Return: 0 always.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates 5 zombie process and hangs parent process.
 *
 * Return: 0 if success and 1 otehrwise.
 */
int main(void)
{
	pid_t pid;
	int i;

	i = 0;

	while (++i < 6)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork Failed!");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Zombie process created, PID: %d\n", (int) getpid());
			exit(EXIT_SUCCESS);
		}
	}
	infinite_while();
	return (EXIT_SUCCESS);
}
