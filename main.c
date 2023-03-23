#include "monty.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: standard exit - success or failure
 */
int main(int ac, char **av)
{
	char *file_name, line[254], *tok, *command;
	FILE *monty_file;
	stack_t *head;
	void (*instruction)(stack_t * *stack, unsigned int line_number);
	unsigned int line_number;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = av[1];
	monty_file = fopen(file_name, "r");
	head = NULL;
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(line, sizeof(line), monty_file))
	{
		instruction = get_instruction(line, line_number);
		instruction(&head, line_number);
		line_number++;
	}
	exit(EXIT_SUCCESS);
}