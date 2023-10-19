#ifndef MONTY
#define MONTY
#define _GNU_SOURCE
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct info_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @isqueue: check if queue
 * Description: carries values through the program
 */
typedef struct info_s
{
	char *arg;
	FILE *file;
	char *content;
	int isqueue;
} info;
extern info glob;
/* stack funcs */
int stack_size(stack_t *head);
int pop(stack_t **head);
stack_t *push(stack_t **head, int n);
void free_stack(stack_t **head);

/* functions in struct*/
void pint_t(stack_t **head, unsigned int lc);
void pall(stack_t **h, unsigned int lc);
void push_t(stack_t **head, unsigned int counter);
void pop_t(stack_t **head, unsigned int);
void swap_t(stack_t **head, unsigned int linenum);
void add(stack_t **head, unsigned int lc);
void nop(stack_t **h, unsigned int lc);
void sub(stack_t **h, unsigned int lc);
void div_i(stack_t **h, unsigned int lc);
void mul(stack_t **h, unsigned int lc);
void mod(stack_t **h, unsigned int lc);
void pstr(stack_t **head, unsigned int lc);
void pchar(stack_t **h, unsigned int lc);
/* queue funcs */
int popqueue(stack_t **head);
stack_t *pushqueue(stack_t **head, int n);
void isqueue(stack_t **head, unsigned int linenum);
void isstack(stack_t **head, unsigned int lc);
/* execution funcs */
int exec(char *content, stack_t **stack, unsigned int count, FILE *f);
#endif
