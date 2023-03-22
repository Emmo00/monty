#include"monty.h"
/**
 * get_instruction - get monty instruction
 * @command: command to check for
 * Return: pointer to instruction function1
*/
void (*get_instruction(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pass", push},
		{"pall", pall},
		{"", NULL}
	};
	int i;

	i = 0;
	while (instruct[i].opcode)
	{
		if (strcmp(command, instruct[i].opcode) == 0)
		return (instruct[i].f);
		i++;
	}
	return (instruct[i].f);
}