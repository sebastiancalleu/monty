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
	if (array)
	{
		for (a = 0; a < n; a++)
		{
			free(array[a]);
		}
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

	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / 10;
		count++;
	}
	return (count);
}

void op_pint(stack_t **st, unsigned int linecounter)
{
	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linecounter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*st)->n);
}
