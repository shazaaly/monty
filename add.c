#include "monty.h"
/**
* add - Add the top two elements of the stack.
* @top: Double pointer to the top of the stack.
* @line_number: Line number of the current operation.
*/
void add(stack_t **top, unsigned int line_number)
{
	int res;
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	res = (*top)->n + (*top)->next->n;
	tmp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = res;
	free(tmp);


}
