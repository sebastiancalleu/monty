#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct storage_s
{
        char **arr_of_buff;
		char *bufcop;
} storage_t;

/* auxfunctions.c */
int openfile(char **, stack_t **);
void executor(char *, stack_t **, unsigned int);
void (*get_op_func(char *, unsigned int linecounter))(stack_t **, unsigned int);
void op_push(stack_t **, unsigned int);
void op_pall(stack_t **, unsigned int);

/*auxfunctions_1.c */
int wrdcounter(char *);
void free_arr(char **, int n);
void freelist(stack_t **);
unsigned int countdigs(int);
void op_pint(stack_t **, unsigned int);

/*auxfunctions_2.c*/
void freeall(stack_t **);
void op_pop(stack_t **, unsigned int);
void op_swap(stack_t **, unsigned int);
int stackelements(stack_t **);
void op_nop(stack_t **st, unsigned int linecounter);

/*auxfunctions_3.c*/
void op_add(stack_t **, unsigned int);
void op_sub(stack_t **, unsigned int);
void op_div(stack_t **, unsigned int);
void op_mul(stack_t **, unsigned int);
void op_mod(stack_t **, unsigned int);

/*auxfunctions_4.c*/
void op_pchar(stack_t **, unsigned int);
void op_pstr(stack_t **, unsigned int);
void op_rotl(stack_t **, unsigned int);
void op_rotr(stack_t **, unsigned int);

storage_t strge;

#endif