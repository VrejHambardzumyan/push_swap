/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:21:59 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:23:42 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			s = -s;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = 10 * res + (str[i++] - '0');
		if (res == -2147483648)
			return (-2147483648);
		if (res < 0)
			return (0);
	}
	return (res * s);
}
