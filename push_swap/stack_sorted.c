#include "push_swap.h"

static bool stack_sorted(t_node **stack)
{
	t_node *current;
	t_node *next_node;

	if (*stack == NULL)
		return (true);
	current = *stack;
	next_node = current->next;
	while (next_node != *stack)
	{
		if (current->value > next_node->value)
			return (false);
		current = next_node;
		next_node = next_node->next;
	}
	return (true);
}