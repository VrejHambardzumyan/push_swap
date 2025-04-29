#include "push_swap.h"

static void sort_tree(t_node **stack)
{
	t_node *current;
	t_node *next_node;
	int max;
	
	max = find_max(stack);
	current = *stack;
	next_node = current->next;
	while(current->next !=  stack)
	{	
		if(current->value == max)
			ra(stack,false);
		else if(current->value > current->next->value)
			sa(stack,false);
		current = current->next;
	}
}

static int find_max(t_node **stack)
{
	t_node *current;
	int max;

	max = INT_MIN;
	current = *stack;
	while (current->next != *stack)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
}