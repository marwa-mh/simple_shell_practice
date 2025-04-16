#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_path_dirs(void)
{
	char *path_env = getenv("PATH");
	char *token;
	char *path_copy;

	if (path_env == NULL)
	{
		printf("PATH variable not found.\n");
		return;
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup failed");
		return;
	}
	token = strtok(path_copy, ":");
	while (token !=NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	free(path_copy);
}
int main(void)
{
	print_path_dirs();
	return (0);
}
