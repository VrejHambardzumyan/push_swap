/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:00 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:53:05 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

static t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	int		max;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	sort_three(t_node **stack)
{
	t_node	*current;
	t_node	*max;

	max = find_max(*stack);
	current = *stack;
	if (current == max)
		ra(stack, false);
	else if (current->next == max)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}

void	handle_five(t_node **stack_a, t_node **stack_b)
{
	while (stack_length(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);
		finish_rotate(stack_a, find_min(*stack_a), 'a');
		pb(stack_b, stack_a, false);
	}
}
