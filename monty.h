#ifndef MONTY_H
#define MONTY_H

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stddef.h>



/**
 * struct stack_s - Stack structure
 *
 * @n: Integer value stored in the stack
 * @prev: Pointer to the previous node in the stack
 * @next: Pointer to the next node in the stack
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Instruction structure
 *
 * @opcode: String representing the instruction opcode
 * @arg: String representing the argument for the instruction
 * @f: Pointer to the function that executes the instruction
 */
typedef struct instruction_s
{
	char *opcode;
	char *arg;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Function prototypes */
void push(stack_t **stack, char *arg);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void process_file(FILE *file, stack_t **stack);
struct instruction_s *create_instruction(char *opcode, void *arg);
void execute_instruction(struct instruction_s *instruction, stack_t **stack,
		unsigned int line_number);
char *my_strdup(const char *str);

/*helper functions */
char *my_strdup(const char *str);
int my_getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MONTY_H */

