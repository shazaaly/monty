#include "monty.h"

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int data;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack" , line_number);
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	data = tmp->n;
	printf("%d\n", data);
	*top = (*top)->next;
	free(tmp);
}