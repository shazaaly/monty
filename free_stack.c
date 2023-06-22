#include "monty.h"
/**
* free_stack - Frees all the nodes of a stack.
* @stack: Pointer to the top of the stack.
*
* Description: This function frees all the nodes of a stack, starting from
*              the top of the stack.
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *tmp = NULL; /* Initialize tmp to NULL */

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL; /*Set the top of the stack to NULL */
}
