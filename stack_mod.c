#include "monty.h"
/**
* stack_mod- mod the second top element of the stack by the top element.
* @top: Double pointer to the top of the stack.
* @line_number: Line number of the current operation.
*/
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

