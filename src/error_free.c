/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:33:29 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/06 17:32:06 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char *argv[])
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*curr;

	if (stack == NULL)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	free_error(t_node **stack, char *argv[], bool flag)
{
	free_stack(stack);
	if (flag)
		free_arr(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	error_duplicate(t_node *stack, int value)
{
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
