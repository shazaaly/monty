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
	FILE *myfile;
	char *filename = NULL;
	char *line = NULL;
	size_t len = 0;
	int bytes_read;
	unsigned int line_number = 0;
    stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	myfile = fopen(filename, "r");

	if (!myfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*read line*/
	while ((bytes_read = getline(&line, &len, myfile)) != -1)
	{
		line_number++;
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		if (bytes_read > 0)
		{
			execute(line, line_number, &stack, myfile);
		}
		free(line);

	}
	fclose(myfile);
	free_stack(&stack);
	return (0);
}


