/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:02:42 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:23:56 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_num_length(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*res;

	len = get_num_length(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	num = n;
	if (n < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (n == 0)
		return (*res = '0', res);
	while (num)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
// #include <stdio.h>
// int main ()
// {
// 	printf("%sresultt", ft_itoa(9));
// }
