/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:01:08 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:51:49 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **stack_a, t_node **stack_b,
		t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b, false);
	set_curr_position(*stack_a);
	set_curr_position(*stack_b);
}

static void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
		t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, false);
	set_curr_position(*stack_a);
	set_curr_position(*stack_b);
}

void	finish_rotate(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	push_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = return_cheapest(*stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest);
	finish_rotate(stack_a, cheapest->target_node, 'a');
	finish_rotate(stack_b, cheapest, 'b');
	pa(stack_a, stack_b, false);
}

void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest;
	int		length_a;

	length_a = stack_length(*stack_a);
	if (length_a == 5)
		handle_five(stack_a, stack_b);
	else
	{
		while (length_a-- > 3)
			pb(stack_a, stack_b, false);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes(*stack_a, *stack_b);
		push_nodes(stack_a, stack_b);
	}
	set_curr_position(*stack_a);
	smallest = find_min(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a, false);
	else
		while (*stack_a != smallest)
			rra(stack_a, false);
}
