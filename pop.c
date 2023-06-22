#include "monty.h"

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack" , line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	*top = tmp->next;


	free(tmp);
}