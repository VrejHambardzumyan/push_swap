/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:04:21 by vhambard          #+#    #+#             */
/*   Updated: 2025/02/04 18:04:23 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
int		ft_signed(long long s);
int		ft_convcheck(char s);
int		ft_putnbr_base(unsigned int num, const char *s, unsigned int base);
int		ft_funcfetch(va_list args, const char *s);
int		ft_putptr(unsigned long long num, char *s,
			size_t base);

#endif