#include "monty.h"
/**
 * mod -  rest of the division of the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	*stack = tmp->next;
	free(tmp);
}
/**
 * comment -  comment code (ignore)
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * pchar - prints the char at the top stack, followed
 * by new line.
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: pointer to pointer to head of stack_t
 * @line_number: line number being read
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char c;
	(void)line_number;

	if (*stack == NULL)
		return;
	node = *stack;
	while (node != NULL)
	{
		c = node->n;
		if (c == 0 || c > 127)
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}
