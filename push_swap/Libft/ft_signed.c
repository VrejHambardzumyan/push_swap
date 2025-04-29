/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:10:05 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:26 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_signed(long long num)
{
	if (num < 0)
		return (ft_putchar('-') + ft_putnbr_base(-num, "0123456789", 10));
	return (ft_putnbr_base(num, "0123456789", 10));
}
