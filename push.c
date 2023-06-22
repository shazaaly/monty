#include "monty.h"

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
	/* checks if the value returned by atoi is 0, and also checks if the first character of the argument string is not '0' */
	if (*endptr != '\0' || endptr == col.arg)
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