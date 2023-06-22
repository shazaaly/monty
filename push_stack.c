#include "monty.h"

void push_stack(stack_t **top, int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*top != NULL) /* stack not empty */
    {
        new_node->next = *top;
        (*top)->prev = new_node;
    }

    *top = new_node;
}