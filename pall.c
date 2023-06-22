#include "monty.h"
/**
* pall - Prints all the values on the stack, from top to bottom.
* @head: A pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
* Return - void.
*/
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *h = NULL;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
