#include "monty.h"
/**
 * get_instruction - get monty instruction
 * @line: string to extract command
 * Return: pointer to instruction function1
 */
int n = 0;

void (*get_instruction(char *line, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pall", pall},
		{"pass", push},
		{"", NULL}};

	int i;
	char *command;

	i = 0;
	command = strtok(line, " \n");
	if (strcmp(command, "pall") == 0)
		return (instruct[i].f);
	i++;
	if (strcmp(command, "pass") == 0)
	{
		command = strtok(NULL, " \n");
		n = atoi(command);
		if (n == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		return (instruct[i].f);
	}
	i++;
	return (instruct[i].f);
}
