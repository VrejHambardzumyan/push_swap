#include "push_swap.h"

static void add_node(t_node **stack, int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		return ;
	}else
	{
		new_node->next = *stack;
	}
}

static void stack_init(t_node **stack, char **arr)
{
	int i ;
	long j;

	i = 0;
	while (arr[i])
	{
		if (error_arg(arr[i]) == 1)
			free_errror(stack); 
		j = (long)ft_atoi(arr[i]);
		
		if (j> INT_MAX || j < INT_MIN)
			free_errror(stack);
		if (error_duplicate(*stack, j) == 1)
			free_errror(stack);
		add_node(stack, (int)j);
		i++;
	}
}