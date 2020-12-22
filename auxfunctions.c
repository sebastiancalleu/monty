#include "monty.h"

int openfile(char **argv, stack_t **st)
{
	char *buffer = NULL;
	size_t bufflen = 0;
	FILE *fp;
	unsigned int linecounter = 0;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&buffer, &bufflen, fp) != -1)
	{
		linecounter++;
		executor(buffer, st, linecounter);
	}
	if (st != NULL)
		freelist(st);
	fclose(fp);
	if (buffer)
		free(buffer);
	exit(EXIT_SUCCESS);
}

void executor(char *buffer, stack_t **st, unsigned int linecounter)
{
	char *token = NULL;
	char *delim = " \n";
	int a = 0, n = 0;

	n = wrdcounter(buffer);
	token = strtok(buffer, delim);
	strge.arr_of_buff = malloc((n + 1) * sizeof(char));
	if (strge.arr_of_buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while(token != NULL)
	{
		strge.arr_of_buff[a] = malloc((strlen(token) + 1) * sizeof(char));
		if (strge.arr_of_buff[a] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(strge.arr_of_buff[a], token);
		token = strtok(NULL, delim);
		a++;
	}
	strge.arr_of_buff[a] = NULL;
	get_op_func(strge.arr_of_buff[0], linecounter)(st, linecounter);
	free_arr(strge.arr_of_buff, n);
	free (strge.arr_of_buff);
}

void (*get_op_func(char *s, unsigned int linecounter))(stack_t **st, unsigned int linecounter)
{
	instruction_t ops[] = {
	{"push", op_push},
	{"pall", op_pall},
	{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}
	fprintf(stderr, "L<%u>: unknown instruction <%s>\n", linecounter, s);
	exit(99);
	return (NULL);
}

void op_push(stack_t **st, unsigned int linecounter)
{
	stack_t *new = NULL;
	int a;
	if (!strge.arr_of_buff[1])
	{
		printf("L<%d>: usage: push integer\n", linecounter);
		exit(EXIT_FAILURE);
	}
	a = atoi(strge.arr_of_buff[1]);
	if((a == 0 && (strge.arr_of_buff[1][1] != '0')) || (countdigs(a) != strlen(strge.arr_of_buff[1])) || !a)
	{
		printf("L<%d>: usage: push integer\n", linecounter);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = a;
	new->prev = NULL;
	new->next = *st;
	*st = new;
}

void op_pall(stack_t **st, unsigned int linecounter)
{
	int a = 0;
	stack_t *tmp = NULL;

	if (strge.arr_of_buff[1] != NULL)
	{
		printf("L<%d>: usage: push integer\n", linecounter);
		exit(EXIT_FAILURE);
	}

	tmp = *st;
	for (a = 0; tmp != NULL; a++)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}