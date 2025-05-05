/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:05 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:18 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ete taza nod enq kpcnum orinka stack_a in, petqa amenaverjin 
nody update anenq vor nayi taza kcac nodi vra, te arden mer verjin 
nody samo saboy nayuma headin, menka heady poxenq klni ok
*/

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_node **stack_a, bool print)
{
	swap(stack_a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, bool print)
{
	swap(stack_b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		write(1, "ss\n", 3);
}
