/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcfetch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:57:48 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:23:53 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_funcfetch(va_list args, const char *s)
{
	if (*s == 'i' || *s == 'd')
		return (ft_signed(va_arg(args, int)));
	else if (*s == 'u')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 10));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == '%')
		return (ft_putchar('%'));
	else if (*s == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 16));
	else if (*s == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 16));
	else if (*s == 'p')
		return (ft_putstr("0x") + ft_putptr(va_arg(args, unsigned long long),
				"0123456789abcdef", 16));
	return (0);
}
