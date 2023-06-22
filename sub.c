#include "monty.h"
/**
* sub - Subtract the top element of the stack from the second top element.
* @top: Double pointer to the top of the stack.
* @line_number: Line number of the current operation.
*/
void sub(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	res = (*top)->n - (*top)->next->n; /*subtract*/
	tmp = *top;
	*top = (*top)->next; /*new top is sec node*/
	(*top)->prev = NULL;
	(*top)->n = -(res);
	free(tmp);

}
