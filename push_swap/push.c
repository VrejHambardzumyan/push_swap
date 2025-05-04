#include "push_swap.h"

static void push(t_node **stack_a, t_node **stack_b)
{
	t_node *node_to_push;

	if (*stack_b == NULL)
		return ;
	node_to_push = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node_to_push;
		node_to_push->next = NULL;
	}else{
		node_to_push->next = *stack_a;
		(*stack_a)->prev = node_to_push;
		*stack_a = node_to_push;
	}
}
void pa(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);	
	if (!print)
		ft_printf("pa\n");
}
void pb(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);	
	if (!print)
		ft_printf("pb\n");
}