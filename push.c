#include "monty.h"

/**
 * push - Adds a new element to the top of the stack.
 *
 * @top: A pointer to the top of the stack.
 * @line_number: The line number of the instruction being executed.
 */
void push(stack_t **top, unsigned int line_number)
{
    int value;
    char *endptr;

    /* Check if argument is present */
    if (col.arg)
    {
        int i = 0;

        /* Check if argument is negative */
        if (col.arg[0] == '-')
        {
            i++;
        }

        /* Check if argument is a valid integer */
        for (; col.arg[i] != '\0'; i++)
        {
            if (col.arg[i] > 57 || col.arg[i] < 48)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free_stack(top);
                free(col.line);
                fclose(col.file);
                exit(EXIT_FAILURE);
            }
        }
    }
    else /* Argument is not present */
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(top);
        free(col.line);
        fclose(col.file);
        exit(EXIT_FAILURE);
    }

    /* Check if argument is empty or contains only whitespace */
    if (col.arg == NULL || *col.arg == '\0' || isspace(*col.arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(top);
        free(col.line);
        fclose(col.file);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer */
    value = strtol(col.arg, &endptr, 10);

    /* Check if conversion was successful */
    if (*endptr != '\0' || endptr == col.arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(top);
        free(col.line);
        if (col.file != NULL)
            fclose(col.file);
        exit(EXIT_FAILURE);
    }

    /* Add new node to the stack */
    push_stack(top, value);
}