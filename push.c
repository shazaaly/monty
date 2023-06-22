#include "monty.h"
/**
* push - Adds a new element to the top of the stack.
* @top: A pointer to the top of the stack.
* @line_number: The line number of the instruction being executed.
*/
void push(stack_t **top, unsigned int line_number)
{
	int value;
	char *endptr;

	if (col.arg == NULL || *col.arg == '\0' || isspace(*col.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(top);
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
	value = strtol(col.arg, &endptr, 10);

	if (*endptr != '\0' || endptr == col.arg ||
	 value > INT_MAX || value < INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(top);
		free(col.line);
		if (col.file != NULL)
			fclose(col.file);
		exit(EXIT_FAILURE);
	}
		push_stack(top, value);
}
