#include "monty.h"

storage_t strge;

int main(int argc, char **argv)
{
	stack_t *st = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		openfile(argv, &st);
	}
	return (0);
}
