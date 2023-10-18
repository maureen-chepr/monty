#include "monty.h"

/**
 * main - function that interprates monty bytecode
 * @argc: argument count
 * @argv: argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *filepath, *comd_line, *opcode;
	FILE *file;
	size_t size = 0;
	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filepath = argv[1];
	file = fopen(filepath, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s \n", filepath);
		exit(EXIT_FAILURE);
	}

	while (getline(&comd_line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(comd_line, " \t\n");

		if (opcode == NULL || strlen(opcode)== 0 )
			continue;
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free(comd_line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	free(comd_line);
	fclose(file);
	return (0);
}
