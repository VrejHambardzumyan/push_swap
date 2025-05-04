/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:55:45 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/29 15:25:42 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node *stack_a;
    t_node *stack_b;
    bool flag;

    stack_a = NULL;
    stack_b = NULL;

    char **arr = NULL;
    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else {
        arr = ft_split(merge_arg(argc, argv), " ");
    }
    flag = true;
    //           ste kam arr, kam arr+1
    creat_stack(&stack_a, arr, flag);
    if (!stack_sorted(stack_a))
    {
        if(stack_length(stack_a) == 2)
            sa(&stack_a,false);
        else if(stack_length(stack_a) == 3)
            sort_three(&stack_a);
        else 
            sort_stacks(&stack_a, &stack_b);//push_swap
    }

    free_stack(&stack_a);

	/*
	1)pahum enq double linked list,vor hesht lini rra/rrb anely
	
	2)pti split-ov parsing arvi argv[1]-y; amen tiv hat hat lcvi 
	stacki noderi mej;
	
	3)karanq vapshe funckcianery 5 haty mek  lcenq mi fayli mej,	
	
	4)u vrodi mnuma checkerner grel, meke algorithmy nayel sortingi

	------------algorithmy - butterfly sort
	
	*/
	
}
