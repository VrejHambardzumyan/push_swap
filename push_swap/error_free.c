#include "push_swap.h"

void free_arr(char *argv[])
{
	int i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void free_stack(t_node **stack)
{
	t_node *temp;
	t_node *curr;

	if (stack == NULL)
		return ;
	curr = *stack; 	
	while (stack != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void free_error(t_node **stack,char *argv[], bool flag)
{
	free_stack(stack);
	if (flag)
		free_arr(argv);
	write(2,"Error\n",6);
	exit(1);
}

int error_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (1);
		if ( arg[i] == '-'|| arg[i] == '+' && !ft_isdigit(arg[i]) )
			return (1);
		while (*++arg)
		{
			if (!(*arg >= '0' && *arg <= '9'))
				return (1);
		}
	}
	return (0);
}

int error_duplicate(t_node *stack, int value)
{
	if (stack == NULL)
		return (0);

	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}