#include "monty.h"
/**
* mul - Multiplies the second top element of the stack with the top element
* @top: Double pointer to the top of the stack
* @line_number: Line number being executed from the Monty file
*/
void mul(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
		if (!is_integer((*top)->n) || !is_integer((*top)->next->n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	res = (*top)->n * (*top)->next->n;
	tmp = *top;
	*top = (*top)->next; /*new top is sec node*/
	(*top)->prev = NULL;
	(*top)->n = res;
	free(tmp);

}
/**
 * is_integer - Checks if a given number is an integer
 * @num: The number to check
 *
 * Return: 1 if the number is an integer, 0 otherwise
 */
int is_integer(int num)
{
	if (num == (int)num)
		return (1);
	else
		return (0);
}
