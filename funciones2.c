#include "monty.h"

/**
 * _isdigit - Returns 1 if a number 0 if not
 * @number: String with the posible number
 * Return: 1 if string is a number, 0 if it isnt
 */
int _isdigit(char *number)
{
	int i = 0;

	if (number[0] == '-')
		i = 1;
	for (; number[i] != '\0'; i++)
	{
		if (number[i] < '0' && number[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * free_all - Frees memory
 * @stack: Pointer to the stack
 */
void free_all(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
	free(global.line);
}

/**
 * sub - Substract the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
