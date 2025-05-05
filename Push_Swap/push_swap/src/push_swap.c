/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:55:45 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 20:52:42 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	bool	flag;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	arr = ft_split(merge_arg(argc, argv), ' ');
	printf("%s\n",arr[0]);
}
	/*flag = true;
	create_stack(&stack_a, arr+1, flag);//           ste kam arr, kam arr+1
	if (!stack_sorted(stack_a))
	{
		if (stack_length(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_length(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}*/
