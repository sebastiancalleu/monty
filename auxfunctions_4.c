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