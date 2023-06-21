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
    stack_t *current, *temp;

    if (stack == NULL || *stack == NULL)
        return;

    current = *stack;

    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    *stack = NULL;
}