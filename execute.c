#include "monty.h"

/**
 * execute_opcode - verifies opcode commands before execution
 * @stack: Stack or Queue
 * Return: 0 On Valid Command 1 On Command Not Found
 */
int execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int idx = 0;

	instruction_t command[] = {
		{"push", push_opcde},
		{"pall", pall_opcde},
		{"pint", pint_opcde},
		{"pop", pop_opcde},
		{"swap", swap_opcde},
		{NULL, NULL}
	};
	
	while (command[idx].opcode != NULL)
	{
		if (strcmp(command[idx].opcode, opcode) == 0)
		{
			command[idx].f(stack, line_number);
			return (0);
		}
		idx++;
	}
	return (1);
}
