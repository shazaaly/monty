#include "monty.h"
/**
* execute - Executes an opcode on a stack.
* @line: The line containing the opcode to execute.
* @line_number: The line number of the opcode in the input file.
* @stack: A pointer to the top of the stack.
* Return: 0 if the opcode is a comment or if the line is empty, 1 otherwise.
*/
int execute(char *line, unsigned int line_number, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", stack_div},
		{"mod", stack_mod},
		{NULL, NULL}
	};
	int i = 0;
	int found = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	col.arg = strtok(NULL, " \t\n");
	/* loop all ops to compare opcode extracted */
	while (opcodes[i].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			found = 1;
			break;
		}
		i++;
	}
	if (found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}
