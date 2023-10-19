#include "monty.h"

/**
 * mod_opcde - division of the second with top element
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void mod_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pchar_opcde - prints the character at the top of the stack
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void pchar_opcde(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascii = (*stack)->n;

	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii);
	putchar('\n');
}

/**
 * pstr_opcde - prints the string starting at the top of the stack
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void pstr_opcde(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl_opcde - rotates the stack to the top
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void rotl_opcde(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cp;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->n;
		for (cp = *stack; cp->next != NULL; cp = cp->next)
			cp->n = cp->next->n;
		cp->n = temp;
	}
}

/**
 * rotr_opcde - rotates the stack to the bottom
 * @stack: pointer to head node
 * @line_number: position of the line number
 * Return: void
 */
void rotr_opcde(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *cp;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		cp = *stack;
		next = cp->n;
		while (cp->next)
		{
			current = next;
			next = cp->next->n;
			cp->next->n = current;
			cp = cp->next;
		}
		(*stack)->n = next;
	}
}
