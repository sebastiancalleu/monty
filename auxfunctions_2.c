#include "monty.h"

void freeall(stack_t **st)
{
	freelist(st);
	free_arr(strge.arr_of_buff, 2);
	free(strge.arr_of_buff);
}

void op_pop(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp = NULL;

	if (*st == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp = *st;
	(*st) = (*st)->next;
	if (tmp->next)
		(*st)->prev = NULL;
	free(tmp);
}

void op_swap(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp1 = NULL;
	int a;

	if (stackelements(st) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp1 = *st;
	a = tmp1->n;
	tmp1->n = tmp1->next->n;
	tmp1->next->n = a;
}

int stackelements(stack_t **st)
{
	stack_t *tmp;
	int a = 0;

	tmp = *st;
	while (tmp != NULL)
	{
		a++;
		tmp = tmp->next;
	}
	return (a);
}