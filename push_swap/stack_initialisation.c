#include "push_swap.h"

void create_stack(t_node **stack, char **arr, bool flag)
{
	int i;
	long j;

	i = 0;

	while (arr[i])
	{
			if (error_arg(arr[i]) == 1)
				free_error(stack,arr, flag); 
			j = (long)ft_atoi(arr[i]);
		
			if (j> INT_MAX || j < INT_MIN)
				free_error(stack, arr, flag);
			if (error_duplicate(*stack, j) == 1)
				free_error(stack, arr, flag);
			add_node(stack, (int)j);
			++i;
	}
	if (flag)
		free_arr(arr);
}
