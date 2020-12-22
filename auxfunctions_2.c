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
	free(tmp);
	(*st)->prev = NULL;
}