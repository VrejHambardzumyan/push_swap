/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:28:34 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:08 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		len;

	len = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (ft_convcheck(*s))
			{
				len += ft_funcfetch(list, s);
				s++;
			}
		}
		if (*s != '%' && *s)
		{
			len += ft_putchar(*s);
			s++;
		}
	}
	va_end(list);
	return (len);
}
