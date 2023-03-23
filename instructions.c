#include "monty.h"
/**
 * push - add a new node to the stack stack_t
 * @stack: pointer to pointer to head of stack_t
 * @line_number: line number being read
 * Return: nothing
 */
stack_t *push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
	return (node);
}
/**
 * pall - print all nodes in a stack stack_t
 * @stack: pointer to pointer to head of stack_t
 * @line_number: line number being read
 * Return: nothing
 */
unsigned int pall(stack_t **stack, unsigned int line_number)
{
	unsigned int len;
	stack_t *node;
	__attribute__((unused)) line_number;

	len = 0;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
		len++;
	}
	return (len);
}
