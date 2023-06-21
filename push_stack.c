#include "monty.h"

stack_t *push_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr,"Error: malloc failed");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL; /*if empty stack*/

	if (*stack) /*stack not empty*/
	{
		new_node->next = *stack; /*new node points to current top*/
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;

	*stack = new_node;
	return (new_node);
}