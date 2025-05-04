#include "push_swap.h"

static void reverse_rotate(t_node **stack)
{
	t_node *last;
	int len;

	len = stack_length(*stack);

	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	
	last = ft_find_the_tail(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev =last;
}

void rra(t_node **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}

void rrb(t_node **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}

void rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}