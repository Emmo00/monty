#include "monty.h"
int n;
/**
 * get_instruction - Get Monty instruction
 * @line: String to extract command
 * @line_number: Line number of the current command
 * @stack: double pointer to the beginning of the stack
 * Return: Pointer to instruction function
 */
void (*get_instruction(char *line, unsigned int line_number))(
	stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"", NULL}
	};

	int i = 0, n = 0;
	char *command;

	command = strtok(line, " \n");
	if (command == NULL)
	{
		fprintf(stderr, "L%d: invalid command\n", line_number);
		exit(EXIT_FAILURE);
	}
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
