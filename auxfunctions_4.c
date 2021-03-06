#include "monty.h"

void op_pchar(stack_t **st, unsigned int linecounter)
{
	if (*st == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	if ((*st)->n <= 0 || (*st)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	putchar((*st)->n);
	putchar('\n');
}

void op_pstr(stack_t **st, unsigned int linecounter)
{
	int a;
	stack_t *tmp;

	(void)linecounter;
	tmp = *st;
	if (*st == NULL)
	{
		putchar('\n');
	}
	else
	{
		for (a = 0; tmp != NULL; a++)
		{
			if (tmp->n > 0 && tmp->n < 127)
			{
				putchar(tmp->n);
				tmp = tmp->next;
			}
			else
			{
				break;
			}
		}
		putchar('\n');
	}
}

void op_rotl(stack_t **st, unsigned int linecounter)
{
	int a, b;
	stack_t *tmp;

	(void)linecounter;
	tmp = *st;
	b = tmp->n;
	for (a = 0; tmp != NULL; a++)
	{
		if (tmp->next == NULL)
		{
			tmp->n = b;
			break;
		}
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
}

void op_rotr(stack_t **st, unsigned int linecounter)
{
	int a;
	stack_t *tmp, *tmp1;

	(void)linecounter;
	tmp = *st;
	for (a = 0; tmp->next != NULL; a++)
	{
		tmp = tmp->next;
	}
	*st = tmp;
	for (a = 0; tmp != NULL; a++)
	{
		tmp->next = tmp->prev;
		tmp = tmp->next;
	}
	(*st)->prev = NULL;
	tmp = *st;
	for (a = 0; tmp != NULL; a++)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		if (tmp != NULL)
			tmp->prev = tmp1;
	}
}