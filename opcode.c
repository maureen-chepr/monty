#include "monty.h"

/**
 * push_opcde - function that pushes an element to the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void push_opcde(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_el;

	(void)line_number;

	arg = strtok(NULL, " \n");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	new_el = malloc(sizeof(stack_t));
	if (new_el == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_el->n = value;
	new_el->next = *stack;
	new_el->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_el;
	}
	*stack = new_el;
}

/**
 * pall_opcde - function that prints all the values on the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void pall_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_opcde - function that prints the value at the top of the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void pint_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}

/**
 * pop_opcde - function that removes the top element of the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void pop_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * swap_opcde - function that swaps the top two elements of the stack
 * @stack: pointer to headnode
 * @line_number: position of the line number
 * Return: void
 */

void swap_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = *stack;

	if (temp->next != NULL)
		temp->next->prev = temp;
}
