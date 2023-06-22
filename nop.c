#include "monty.h"
/**
* nop - does nothing
* @top: double pointer to the top of the stack
* @line_number: line number of the opcode
* Description: This opcode does nothing.
* Return: void
*/

void nop(stack_t**top, unsigned int line_number)
{
	/*(void) cast expression*/
	*top = NULL;
	line_number = 1;
	line_number = line_number - 1;
}