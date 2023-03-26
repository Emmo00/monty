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
}
/**
 * sub -  subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n -= tmp->n;
	*stack = tmp->next;
	free(tmp);
}
/**
 * _div -  divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= tmp->n;
	*stack = tmp->next;
	free(tmp);
}
/**
 * mul -  multiplies the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n *= tmp->n;
	*stack = tmp->next;
	free(tmp);
}
