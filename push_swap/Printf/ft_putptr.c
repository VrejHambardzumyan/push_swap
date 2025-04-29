/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:07:36 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:13 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putptr(unsigned long long num, char *s, size_t base)
{
	if (num < base)
		return (ft_putchar(s[num]));
	return (ft_putptr(num / base, s, base)
		+ ft_putptr(num % base, s, base));
}
