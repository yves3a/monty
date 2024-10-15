#include <monty.h>

/**
 * process_file - process the instructions from a file
 * @file: pointer to a file to be processed
 * @stack: pointer to a pointer at the top of the stack
 *
 * Description: Reads the file line by line,
 * tokenizes each line to extract the opcode,
 * creates an instruction and executes it.
 *
 * Return: void
 */

void process_file(FILE *file, stack_t **stack)
{
	char *buff = NULL;
	size_t len = 0;
	int line_number = 1;

	/* Read the file line by line */
	while (my_readline(&buff, &len, file) != -1)
	{
		char opcode = strtok(buff, "\t\n");

		/* if line is not empty, process the opcode */
		if (opcode)
		{
			/* create an instruction for the extracted opcode*/
			instruction_t *instruct = create_instruct(opcode, NULL);

			/* if opcode is invalid or unknown*/
			if (!instruction)
			{
				fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
				exit(EXIT_FAILURE);
			}
			/* execute the valid instruction on the stack */

		}

	}

}

/**
 * create_instruct - create an instruction structure
 * @opcode: The opcode string
 * @arg: The argument for the instruction
 *
 * Return: a pointer to the newly created instruction structure.
 */

instruction_t *create_instruct(char *opcode, void *arg)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (!instruction)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = strdup(opcode);
	instruction->arg = arg;

	return (instruction);
}

