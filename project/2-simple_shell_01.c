#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

#define PROMPT "#customshell$$ "

int main(void)
{
	char *line = NULL;
	char *argv[2];
	size_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;
			if (execve(argv[0], argv, environ) == -1)
				perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	free(line);
	return (0);
}
