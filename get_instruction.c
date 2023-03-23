#include "monty.h"
int n = 0;
/**
 * get_instruction - get monty instruction
 * @line: string to extract command
 * Return: pointer to instruction function1
 */
void (*get_instruction(char *line, unsigned int line_number))
(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"", NULL}
	};

	int i = 0;
	char *command;

	command = strtok(line, " \n");
	if (command == NULL)
		return (NULL);

	while (instruct[i].opcode != NULL)
	{
		if (strcmp(command, instruct[i].opcode) == 0)
		{
			if (strcmp(command, "push") == 0)
			{
				command = strtok(NULL, " \n");
				n = atoi(command);
				if (n == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			return (instruct[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
