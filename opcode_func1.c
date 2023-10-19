#include "monty.h"

/**
 * add_opcde - function that adds the top two elements of the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void add_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop_opcde - function that doesn’t do anything
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void nop_opcde(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_opcde - subtracts the top element
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void sub_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
