/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:37:54 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:15 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (*s)
	{
		i += ft_putchar(*(s++));
	}
	return (i);
}
