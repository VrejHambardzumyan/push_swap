/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:19 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/20 14:32:19 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_total_length(int argc, char *argv[])
{
	int	i;
	int	total_len;

	total_len = 0;
	i = 1;
	while (i < argc)
		total_len += ft_strlen(argv[i++]) + 1;
	return (total_len);
}

static int	parse_and_validate_number(const char *str, int start, int end)
{
	int		i;
	int		is_negative;
	long	result;

	i = start;
	is_negative = 0;
	result = 0;
	if (i < end && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i++] == '-')
			is_negative = 1;
	}
	if (i >= end)
		return (1);
	while (i < end)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		result = result * 10 + (str[i] - '0');
		if ((is_negative && result > (long)INT_MAX + 1)
			|| (!is_negative && result > (long)INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

static int	validate_all_numbers(const char *str)
{
	int	i;
	int	start;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		while (i < len && (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r'))
			i++;
		if (i >= len)
			break ;
		start = i;
		while (i < len && !(str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r'))
			i++;
		if (parse_and_validate_number(str, start, i) == 1)
			return (1);
	}
	return (0);
}

int	validate_arguments(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (validate_all_numbers(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
