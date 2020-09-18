#include "monty.h"

/**
 * getfunction - function reads command string and selects
 * the correct function to perform
 * @s: string
 *
 * Return: pointer corresponding function
 */
void (*getfunction(char *s))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *msg = ": unknown instruction ";

	instruction_t operations[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{"mod", modu},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
		};

	while (operations[i].opcode != NULL)
	{
		if (strcmp(s, operations[i].opcode) == 0)
			return (operations[i].f);
		i++;
	}
	fprintf(stderr, "L%u%s%s\n", global.line_number, msg, s);
	free_all(global.stack);
	fclose(global.file);
	exit(EXIT_FAILURE);
}
