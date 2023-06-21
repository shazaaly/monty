#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the current instruction.
 */
 void push(stack_t **stack, unsigned int line_number)
 {
	char *arg = col.arg;
	int value;
		stack_t *new_node;

	if (!arg)
	{
		fprintf("L%u: usage: push integer\n", line_number);
		free_stack(*head)
		free(bus.line);
		fclose(col.file);
		exit(EXIT_FAILURE););
	}
	value = atoi(arg);
	/*checks if the value returned by atoi is 0, and also checks if the first character of the argument string is not '0'*/
	if (value == 0 || *arg[0] = '0')
	{
		fprintf("L%u: usage: push integer\n", line_number);
		free_stack(*head)
		free(bus.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, value);
 }