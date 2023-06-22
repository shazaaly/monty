#include "monty.h"

void stack_mod(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);

	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);

	}
	tmp = *top;
	res = (*top)->next->n % (*top)->n;
	*top = (*top)->next;
	(*top)->n = res;
	if (*top != NULL)
	{
		(*top)->prev = NULL;

	}
	free(tmp);
}

