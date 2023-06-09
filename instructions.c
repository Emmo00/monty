#include "monty.h"
/**
 * push - add a new node to the stack stack_t
 * @stack: pointer to pointer to head of stack_t
 * @line_number: line number being read
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		free(node);
		fprintf(stderr, "L%d: stack is null\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}
/**
 * pall - print all nodes in a stack stack_t
 * @stack: pointer to pointer to head of stack_t
 * @line_number: line number being read
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	if (*stack == NULL)
		return;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
/**
 * pint - prints the value at the top stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop -  removes the top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	free(tmp);
}
/**
 * swap -  swap the top two elements of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = *stack;
}
