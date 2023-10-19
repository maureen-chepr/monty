#include "monty.h"

/**
 * main - function that interprates monty bytecode
 * @argc: argument count
 * @argv: argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *comd_line = NULL, *opcode;
	FILE *file;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&comd_line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(comd_line, " \t\n");

		if (opcode == NULL || strlen(opcode) == 0)
			continue;
		if (execute_opcode(&stack, opcode, line_number) != 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(comd_line);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	free(comd_line);
	fclose(file);
	return (EXIT_SUCCESS);
}
