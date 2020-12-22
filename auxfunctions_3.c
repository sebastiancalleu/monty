#include "monty.h"

void op_add(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp1 = NULL;

	if (stackelements(st) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp1 = *st;
	tmp1->next->n += tmp1->n;
	*st = (*st)->next;
	if (tmp1->next)
		(*st)->prev = NULL;
	free(tmp1);
}

void op_sub(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp1 = NULL;

	if (stackelements(st) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp1 = *st;
	tmp1->next->n -= tmp1->n;
	*st = (*st)->next;
	if (tmp1->next)
		(*st)->prev = NULL;
	free(tmp1);
}

void op_div(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp1 = NULL;

	if (stackelements(st) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	if ((*st)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp1 = *st;
	tmp1->next->n /= tmp1->n;
	*st = (*st)->next;
	if (tmp1->next)
		(*st)->prev = NULL;
	free(tmp1);
}

void op_mul(stack_t **st, unsigned int linecounter)
{
	stack_t *tmp1 = NULL;

	if (stackelements(st) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linecounter);
		free(strge.bufcop);
		freeall(st);
		exit(EXIT_FAILURE);
	}
	tmp1 = *st;
	tmp1->next->n *= tmp1->n;
	*st = (*st)->next;
	if (tmp1->next)
		(*st)->prev = NULL;
	free(tmp1);
}