/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:46:25 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:47:02 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_the_tail(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		write(1, "rr\n", 3);
}
