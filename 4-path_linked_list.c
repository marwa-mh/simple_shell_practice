#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node;

path_node *build_path_list(void)
{
	char *path = getenv("PATH");
	char *path_copy, *token;
	path_node *head = NULL, *new_node, *current;

	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		new_node = malloc(sizeof(path_node));
        if (!new_node)
        {
            perror("malloc");
            free(path_copy);
            return (NULL);
        }
new_node->dir = strdup(token);
new_node->next = NULL;
if (head == NULL)
	head = new_node;
else
{
	current = head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
token = strtok(NULL, ":");
}
free(path_copy);
return (head);
}

void print_path_list(path_node *head)
{
    path_node *current = head;
    while (current)
    {
        printf("%s\n", current->dir);
        current = current->next;
    }
}
void free_path_list(path_node *head)
{
    path_node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp->dir);
        free(temp);
    }
}
int main(void)
{
    path_node *list = build_path_list();

    if (list == NULL)
    {
        printf("Could not build PATH list\n");
        return (1);
    }

    print_path_list(list);
    free_path_list(list);

    return (0);
}

