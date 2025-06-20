/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:12:46 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/06 16:00:21 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_the_tail(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	if (stack == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

int	stack_length(t_node *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	add_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->curr_position = 0;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = find_the_tail(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
}

t_node	*return_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
