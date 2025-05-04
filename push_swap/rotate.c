#include "push_swap.h"

static void rotate(t_node **stack)
{
	t_node *last;
	int len;

	len = stack_lenght(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = ft_find_the_tail(*stack);

	last->next = *stack;
	*stack = (*stack)->next ;
	(*stack)->prev = NULL; 
	last->next->prev = last;
	last->next->next = NULL;
}

void ra(t_node **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void rb(t_node **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}
