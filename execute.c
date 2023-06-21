
#include "monty.h"




int execute(char *opcode, unsigned int line_number, stack_t **stack, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", push}

	};

	unsigned int found = 0;
	int i = 0;

	/* loop all ops to compare opcode extracted */
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			found = 1;
			opcodes[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		 /* free_stack(*stack); to be done */
		exit(EXIT_FAILURE);
	}

	fclose(file);
	return (1);
}