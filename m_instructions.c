#include"monty.h"
/**
 * add -  add the top two elements of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
    tmp->next->n += tmp->n;
	*stack = tmp->next;
	free(tmp);
}
/**
 * nop -  does nothing
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
    (void)line_number;
    return;
}
