#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = col.arg;
	int value;
	stack_t *new_node;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		/* free_stack(*stack); */
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	/* checks if the value returned by atoi is 0, and also checks if the first character of the argument string is not '0' */
	if (value == 0 && col.arg[0] == '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
	/*	free_stack(*stack);  to be done */
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}

	new_node = push_stack(stack, value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		 /* free_stack(*stack); to be done */
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
}