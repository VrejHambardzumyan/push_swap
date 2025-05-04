#include "push_swap.h"

bool stack_sorted(t_node *stack)
{
	t_node *current ;
	
	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return false;
		current = current->next;
	}
	return true;
}

static t_node *find_max(t_node *stack)
{
	t_node *max_node;
	int max;

	if (!stack)
		return (NULL);
	max = INT_MIN;

	while (stack != NULL)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void sort_tree(t_node **stack)
{
	t_node *current;
	t_node *max;
	
	max = find_max(*stack);
	current = *stack;
	if (current == max)
		ra(stack,false);
	else if (current->next == max)
		rra(stack,false);
	if((*stack)->value > (*stack)->next->value)
		sa(stack,false);
}

void handle_five(t_node **stack_a, t_node **stack_b)
{
	while (stack_length(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);
		finish_rotation(*stack_a, find_min(*stack_a),'a');
		pb(stack_b,stack_a,false);	
	}
}