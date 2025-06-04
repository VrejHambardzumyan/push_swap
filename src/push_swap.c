/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:55:45 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/03 17:32:59 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static	char	**parse_arguments(int argc, char *argv[])
{
	char	*merged_str;
	char	**arr;

	merged_str = merge_arg(argc, argv);
	if (!merged_str)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	arr = ft_split(merged_str, "\t\v\f\r\n ");
	free(merged_str);
	return (arr);
}

static void	execute_sort(t_node **stack_a, t_node **stack_b)
{
	if (stack_sorted(*stack_a))
		return ;
	if (stack_length(*stack_a) == 2)
		sa(stack_a, false);
	else if (stack_length(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_stacks(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	arr = parse_arguments(argc, argv);
	if (!arr)
		return (1);
	create_stack(&stack_a, arr, true);
	execute_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
}
