/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:42:44 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:42:47 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;

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
	}
	else
	{
		node_to_push->next = *stack_a;
		(*stack_a)->prev = node_to_push;
		*stack_a = node_to_push;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		write(1, "pb\n", 3);
}
