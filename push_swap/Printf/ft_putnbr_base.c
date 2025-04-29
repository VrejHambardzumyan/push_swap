/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:22:50 by vhambard          #+#    #+#             */
/*   Updated: 2025/02/06 17:23:17 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr_base(unsigned int num, const char *s, unsigned int base)
{
	if (num < base)
		return (ft_putchar(s[num]));
	return (ft_putnbr_base(num / base, s, base)
		+ ft_putnbr_base(num % base, s, base));
}
