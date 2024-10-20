#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 * Description: Removes the top element of the stack.
 * If the stack is empty, an error message is printed and the program exits.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 * Description: Swaps the top two elements of the stack.
 * If the stack has less than two elements, an error message is
 * printed and the program exits.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		temp->prev = (*stack)->prev;
		(*stack)->prev = temp;
		if ((*stack)->next)
			(*stack)->next->prev = *stack;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 * Description: Adds the top two elements of the stack.
 * If the stack has less than two elements, an error message is
 * printed and the program exits.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function does nothing.
 * It is used as a placeholder for the "nop" instruction.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Remove unused parameter 'stack' and 'line_number' */
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 * Description: Subtracts the top element of the stack from the
 * second top element.
 * If the stack has less than two elements, an error message is
 * printed and the program exits.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "Error: L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

