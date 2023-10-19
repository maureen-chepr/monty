#ifndef _MONTY_H
#define _MONTY_H
#define  _POSIX_C_SOURCE 200809L

/******MY LIBRARIES******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


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

/******OPCODE FUNCTIONS******/
void push_opcde(stack_t **stack, unsigned int line_number);
void pall_opcde(stack_t **stack, unsigned int line_number);
void pint_opcde(stack_t **stack, unsigned int line_number);
void pop_opcde(stack_t **stack, unsigned int line_number);
void swap_opcde(stack_t **stack, unsigned int line_number);
void add_opcde(stack_t **stack, unsigned int line_number);
void nop_opcde(stack_t **stack, unsigned int line_number);
void sub_opcde(stack_t **stack, unsigned int line_number);
/******OPCODE EXECUTION******/
int execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);

/******SUPPORTING FUNCTIONS******/
int _isdigit(int c);
int is_number(char *str);
int is_negative_number(char *str);
#endif
