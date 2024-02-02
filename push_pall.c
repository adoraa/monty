#include "monty.h"
/**
 * _push - pushes an element onto the stack
 * @stack: ** to the top of the stack
 * @line_num: line number in the Monty bytecode file
 * @value: integer value to be pushed onto the stack
 */
void _push(stack_t **stack, unsigned int line_num, int value)
{
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	} new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	} new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - prints all values on the stack
 * @stack: pointer to the top of the stack
 */
void _pall(stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
