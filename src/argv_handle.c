/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:19 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/04 17:04:24 by vhambard         ###   ########.fr       */
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

static int	has_mix_sign(const char *str, int start, int end, int *minus_count)
{
	char	first;
	int		i;

	first = 0;
	i = start;
	*minus_count = 0;
	while (i < end && (str[i] == '+' || str[i] == '-'))
	{
		if (!first)
			first = str[i];
		else if (str[i] != first)
			return (-1);
		if (str[i] == '-')
			(*minus_count)++;
		i++;
	}
	return (i);
}

static int	parse_and_validate_number(const char *str, int start, int end)
{
	int		i;
	int		minus_count;
	long	result;

	minus_count = 0;
	result = 0;
	i = has_mix_sign(str, start, end, &minus_count);
	if (i == -1 || i >= end)
		return (1);
	while (i < end)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		result = result * 10 + (str[i++] - '0');
		if ((minus_count % 2 == 0 && result > INT_MAX)
			|| (minus_count % 2 == 1 && result > (long)INT_MAX + 1))
			return (1);
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
