#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	printf("Address of env:     %p\n",(void *)env);
	printf("Address of environ: %p\n", (void *)environ);

	return (0);
}
