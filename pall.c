#include "monty.h"

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