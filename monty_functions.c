#include "monty.h"

/**
 * process_file - Process the instructions from a file
 * @file: Pointer to the file to process
 * @stack: Double pointer to the top of the stack
 *
 * Description: Reads the file line by line, tokenizes each line to extract
 * the opcode, creates an instruction, and executes it.
 */
void process_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	int line_number = 1;

	while (my_getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode)
		{
			instruction_t *instruction = create_instruction(opcode, NULL);

			if (!instruction)
			{
				fprintf(stderr, "Error: Unknown instruction at line %d: %s\n",
						line_number, opcode);
				free(line);
				exit(EXIT_FAILURE);
			}

			execute_instruction(instruction, stack, line_number);

			free(instruction);
		}

		line_number++;
	}

	free(line);
}

/**
 * create_instruction - Creates an instruction structure
 * @opcode: The opcode string
 * @arg: The argument for the instruction (currently not used)
 *
 * Return: A pointer to the newly created instruction structure
 *
 * Description: Allocates memory for a new instruction structure, sets the
 * opcode field to the provided opcode string, and initializes the arg field
 * to NULL.
 */
instruction_t *create_instruction(char *opcode, void *arg)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (!instruction)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = my_strdup(opcode);
	instruction->arg = arg;

	return (instruction);
}

/**
 * execute_instruction - Executes an instruction
 * @instruction: Pointer to the instruction to execute
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number of the instruction
 *
 * Description: Executes the specified instruction by calling the corresponding
 * function based on the opcode.
 */
void execute_instruction(instruction_t *instruction, stack_t **stack,
		unsigned int line_number)
{
	if (strcmp(instruction->opcode, "push") == 0)
	{
		push(stack, instruction->arg);
	}
	else if (strcmp(instruction->opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(instruction->opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(instruction->opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(instruction->opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(instruction->opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else if (strcmp(instruction->opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else
	{
		fprintf(stderr, "Error: Unknown instruction: %s\n", instruction->opcode);
		free(instruction->opcode);
		free(instruction);
		exit(EXIT_FAILURE);
	}
}

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @arg: The argument to push
 *
 * Description: Creates a new node with the argument as its value and
 * pushes it onto the stack.
 */
void push(stack_t **stack, char *arg)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number of the instruction
 *
 * Description: Prints the value at the top of the stack. If the stack is
 * empty, an error message is printed and the program exits
 * with a failure status.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "Error: L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

