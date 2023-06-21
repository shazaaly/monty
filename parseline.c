#include "monty.h"

void parse_line(char *line, char **opcode, char **arg)
{
	char *token;
	/*skip leading spaces*/
	while (*line == ' ')
	{
		line++;
	}
	/*extract opcode  from line 'push 123' */
	token = strtok(line, " \t\n");
	if (token == NULL)
	{
		*opcode = NULL;
		*arg = NULL;
		return;
	}
	*opcode = token;

	/*extract arg  from line*/
	token = strtok(NULL, " \t\n");
	if (token == NULL)
	{
		*arg = NULL;
		return;
	}
	*arg = token;
	/* remove spaces from arg str*/
	while (*token != '\0')
	{
		*token++;
	}
	/*moving backwards "hello    \t\n" */
	while (*(--token) == ' ')
	{
		*token = '\0';

	}

}