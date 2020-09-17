#include "monty.h"

/**
 * main - Main function
 * @argc: Number of arguments in program
 * @argv: Argument vectors
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	ssize_t read = 0;
	size_t size = 0;
	char *line = NULL, *valor = NULL, *op_command = NULL;
	stack_t *stack = NULL;
	global.stack = stack;
	global.line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &size, global.file)) != -1)
	{
		global.line = line, op_command = strtok(line, " \t\n"), global.line_number++;
		if (op_command == NULL)
			continue;
		if (strcmp(op_command, "push") == 0)
			valor = strtok(NULL, " \t"), push(&stack, valor);
		if (strcmp(op_command, "push") != 0)
			getfunction(op_command)(&stack, global.line_number);
	}
	free_all(stack);
	fclose(global.file);
	return (0);
}
