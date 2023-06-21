#include "monty.h"

/**
* main - Entry point of the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, or EXIT_FAILURE on failure
*/
col_t col = {NULL, NULL, NULL};
int main(int argc, char *argv[])
{
	char *filename = NULL;
	char *line = NULL;
	size_t len = 0;
	int bytes_read;
	int line_number = 0;
	char *opcode = NULL;
	char *arg = NULL;
    stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	col.file = fopen(filename, "r");

	if (!col.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*read line*/
	while ((bytes_read = getline(&line, &len, col.file)) != -1)
	{
		line_number++;
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		if (line)
		{
			parse_line(line, &opcode, &arg);
		}
		else
		{
			free(line);
		}

		if (bytes_read > 0)
		{
			execute(opcode, line_number, &stack);
		}
		else
		{
			fprintf(stderr, "USAGE: monty file\n");
			free(line);
			fclose(col.file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}

	}
	fclose(col.file);
	free_stack(&stack);
	return (0);
}


