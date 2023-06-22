#include "monty.h"

void pint(stack_t **top, unsigned int line_number)
{

	if (*top != NULL)
	{
		printf("%d\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

}