#include "monty.h"

void pall(stack_t *top, unsigned int line_number)
{
	stack_t *node = top;
	while (node != NULL)
	{
		printf("%d", node->n);
		node = node->prev;
	}
	printf('\n');

}