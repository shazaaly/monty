#include "monty.h"
/**
* pint - prints the value at the top of the stack, followed by a new line
* @top: double pointer to the top of the stack
* @line_number: line number of the opcode
* Return: void
*/
void pint(stack_t **top, unsigned int line_number)
{

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}

}
