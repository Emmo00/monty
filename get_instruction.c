#include "monty.h"
int n = 0;
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
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"#", comment},
		{"pchar", pchar},
		{"pstr", pstr},
		{"", NULL}};

	int i = 0;
	char *command, *endptr;
	long int num;

	command = strtok(line, " \n");
	if (command == NULL)
	{
		return (NULL);
	}
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(command, instruct[i].opcode) == 0)
		{
			if (strcmp(command, "push") == 0)
			{
				command = strtok(NULL, " \n");
				if (command == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				num = strtol(command, &endptr, 10);
				if (*endptr != '\0')
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				if (num > INT_MAX || num < INT_MIN)
				{
					fprintf(stderr, "L%d: integer out of range\n", line_number);
					exit(EXIT_FAILURE);
				}
				n = (int)num;
			}
			return (instruct[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
