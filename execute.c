#include "monty.h"
int execute(char *line, unsigned int line_number, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}

	};
	int i = 0;
	int found = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (*opcode == '#')
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

	if (!opcode && found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	return (1);
}