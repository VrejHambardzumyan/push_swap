#include "push_swap.h"

static void free_stack(t_node *stack)
{
	t_node *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
static void free_error(t_node **stack)
{
	free_stack(*stack);
	ft_printf("Error\n");
	exit(1);
}
static int error_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (1);
		i++;
	}
	return (0);
}
static int error_duplicate(t_node *stack, long value)
{
	t_node *current;

	current = stack;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}