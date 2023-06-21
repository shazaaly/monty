#include "monty.h"
/**
* main - Entry point of the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, or EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	int line_number = 0;
	char *opcode, *arg;
    stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*read line*/
	while (bytes_read = getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
	    parse_line(line, &opcode, &arg);
		execute(opcode, line_number, &stack);
		free(line);
		line = NULL;
		len = 0;
	}
	fclose(file);
	return (0);
}


