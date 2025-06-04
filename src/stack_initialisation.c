/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:08 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/04 17:01:14 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_signs(const char *str, int *i, int *sign)
{
	char	first;

	first = 0;
	while (str[*i] && (str[*i] == '+' || str[*i] == '-'))
	{
		if (!first)
		{
			first = str[*i];
			if (str[*i] == '-')
				*sign = -1;
		}
		else if (str[*i] != first)
			return (0);
		(*i)++;
	}
	return (1);
}

static int	parse_and_validate_number(const char *str, int *value)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str || !*str || !is_valid_signs(str, &i, &sign) || !str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long)INT_MAX + 1))
			return (1);
	}
	*value = (int)(result * sign);
	return (0);
}

void	create_stack(t_node **stack, char **arr, bool flag)
{
	int		i;
	int		value;

	i = 0;
	while (arr[i])
	{
		if (parse_and_validate_number(arr[i], &value) == 1)
			free_error(stack, arr, flag);
		if (error_duplicate(*stack, value) == 1)
			free_error(stack, arr, flag);
		add_node(stack, value);
		++i;
	}
	if (flag)
		free_arr(arr);
}
