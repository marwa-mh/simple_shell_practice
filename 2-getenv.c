#include <stdio.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return &environ[i][len + 1];
		i++;
	}
	return (NULL);
}
int main(void)
{
	char *path = _getenv("PATH");
	if (path)
		printf("PATH = %s\n", path);
	else
		printf("Path not found\n");
	char *home = _getenv("HOME");
    if (home)
        printf("HOME = %s\n", home);
    else
        printf("HOME not found\n");

    return (0);
}
