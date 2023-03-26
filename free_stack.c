#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: double pointer to the head of the stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;
	
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
