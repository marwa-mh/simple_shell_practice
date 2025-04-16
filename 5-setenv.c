#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_string;
	size_t name_len, value_len;
	char*existing_value;

	if (name == NULL || value == NULL || strchr(name, '=') != NULL)
		return -1;
	existing_value = getenv(name);
	if (existing_value && !overwrite)
		return 0;
	name_len = strlen(name);
	value_len = strlen(value);
	env_string = malloc(name_len + value_len + 2);
	if (env_string == NULL)
		return -1;
	sprintf(env_string, "%s=%s", name, value);
	if (putenv(env_string) != 0)
	{
		free(env_string);
		return -1;
	}
	return 0;
}
int main(void)
{
	_setenv("MARWA_VAR", "shell_is_fun",1);
	 printf("MARWA_VAR = %s\n", getenv("MARWA_VAR"));

    _setenv("MARWA_VAR", "overwrite_test", 0); // Should NOT overwrite
    printf("MARWA_VAR (no overwrite) = %s\n", getenv("MARWA_VAR"));

    _setenv("MARWA_VAR", "overwrite_test", 1); // Should overwrite
    printf("MARWA_VAR (with overwrite) = %s\n", getenv("MARWA_VAR"));

    return 0;
}
