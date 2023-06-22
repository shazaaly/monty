#include "monty.h"
/**
* pop - Removes the top element of the stack.
* @top: A pointer to the top of the stack.
* @line_number: The line number of the instruction being executed.
*/
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	*top = tmp->next;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	free(tmp);
}
