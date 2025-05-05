/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_initialisation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:02:53 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:52:16 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_curr_position(t_node *stack)
{
	int	i;
	int	mid_stack;

	i = 0;
	if (stack != NULL)
	{
		mid_stack = stack_length(stack) / 2;
		while (stack)
		{
			stack->curr_position = i;
			if (i < mid_stack)
				stack->above_median = true;
			else
				stack->above_median = false;
			stack = stack->next;
			++i;
		}
	}
}

static void	set_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*curr;
	t_node	*target_node;
	long	match_index;

	while (stack_b)
	{
		match_index = LONG_MAX;
		curr = stack_a;
		while (curr)
		{
			if (curr->value > stack_b->value && curr->value < match_index)
			{
				match_index = curr->value;
				target_node = curr;
			}
			curr = curr->next;
		}
		if (match_index == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

static void	set_price(t_node *stack_a, t_node *stack_b)
{
	int	lenght_a;
	int	lenght_b;

	lenght_a = stack_length(stack_a);
	lenght_b = stack_length(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->curr_position;
		if (!(stack_b->above_median))
			stack_b->push_cost = lenght_b - (stack_b->curr_position);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->curr_position;
		else
			stack_b->push_cost += lenght_a
				- (stack_b->target_node->curr_position);
		stack_b = stack_b->next;
	}
}

static void	set_cheapest(t_node *stack)
{
	int		match_value;
	t_node	*match_node;

	if (stack != NULL)
	{
		match_value = INT_MAX;
		while (stack)
		{
			if (stack->push_cost < match_value)
			{
				match_value = stack->push_cost;
				match_node = stack;
			}
			stack = stack->next;
		}
		match_node->cheapest = true;
	}
}

void	init_nodes(t_node *stack_a, t_node *stack_b)
{
	set_curr_position(stack_a);
	set_curr_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}
