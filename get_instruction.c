#include "monty.h"
/**
 * get_instruction - get monty instruction
 * @line: string to extract command
 * Return: pointer to instruction function1
 */
void (*get_instruction(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pass", push},
		{"pall", pall},
		{"", NULL}};
	int i, j;

	i = 0;
	while (instruct[i].opcode)
	{
		if (strncmp(command, instruct[i].opcode, 4) == 0)
		{
			if (command + 4 != NULL)
				int n = atoi(command + 5);
			if (n == 0)
			{
				fprintf(stderr, "L%d: usage: push integer", line_number);
			}
			return (instruct[i].f);
		}
		i++;
	}
	return (instruct[i].f);
}