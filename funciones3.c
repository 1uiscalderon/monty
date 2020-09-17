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
 * modu - Multyplies the top two elements of the stack.
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
