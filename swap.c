#include "monty.h"
/**
* swap - swaps the top two elements of the stack
* @top: double pointer to the top of the stack
* @line_number: line number of the opcode
* Description: If the stack contains less than two elements, swap.
* Return: void
*/
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	int data;


	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	data = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = data;

}
