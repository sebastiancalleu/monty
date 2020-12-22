#include "monty.h"

int wrdcounter(char *str)
{
	int a = 0, b = 0;

	if (str[0] != ' ')
		b++;
	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] != ' ' && str[a - 1] == ' ')
			b++;
	}
	return (b);
}

void free_arr(char **array, int n)
{
	int a = 0;
	for (a = 0; a < n; a++)
	{
		free(array[a]);
	}
}

void freelist(stack_t **head)
{
	int a = 0;
	stack_t *temp;

	for (a = 0; *head != NULL; a++)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

unsigned int countdigs(int a)
{
	unsigned int count = 0;

	while (a != 0)
	{
		a = a / 10;
		count++;
	}
	return (count);
}