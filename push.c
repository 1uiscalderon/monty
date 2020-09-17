#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack
 * @valor: String to analize if is a number or not
 */
void push(stack_t **stack, char *valor)
{
	stack_t *new;
	int num;

	if (_isdigit(valor) == 0 || valor == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", global.line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	num = atoi(valor);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = *stack;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
	global.stack = *stack;
}

/**
 * pall - Prints all the values on the stack,starting from the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;
	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint -  Prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", global.line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number from monty file, print the error in line.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(global.stack);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
