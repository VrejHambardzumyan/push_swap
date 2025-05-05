/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:45:09 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 19:43:35 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_the_tail(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_node **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!print)
		write(1, "rrr\n", 4);
}
