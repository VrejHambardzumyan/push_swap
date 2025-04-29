#include "push_swap.h"

static t_node *find_the_tail(t_node **stack)
{
	t_node *curr;

	curr = *stack;
	if (stack == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
static void add_node(t_node **stack, int value)
{
	t_node *new_node;
	t_node *last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = NULL;
		return ;
	}else
	{	
		last_node  = find_the_tail(stack);
		last_node->next = new_node;
		new_node->next = NULL;
	}
}

static void create_stack(t_node **stack, char **arr)
{
	int i;
	long j;

	i = 0;

	while (arr[i])
	{
			if (error_arg(arr[i]) == 1)
				free_error(stack); 
			j = (long)ft_atoi(arr[i]);
		
			if (j> INT_MAX || j < INT_MIN)
				free_error(stack);
			if (error_duplicate(*stack, j) == 1)
				free_error(stack);
			add_node(stack, (int)j);
			++i;
	}
}
