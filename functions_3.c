#include "monty.h"

/**
 * divi - Divides the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void divi(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * mult- Multyplies the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void mult(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}

/**
 * modu - Modules the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void modu(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int char_to_p;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	char_to_p = (*stack)->n;
	if (char_to_p < 0 || char_to_p > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	putchar(char_to_p);
	putchar('\n');
}

/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int char_to_p;
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	while (tmp != NULL)
	{
		char_to_p = tmp->n;
		if (char_to_p <= 0 || char_to_p > 127)
			break;
		putchar(char_to_p);
		tmp = tmp->next;
	}
	putchar('\n');
}

