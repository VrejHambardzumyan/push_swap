/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:12:11 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:25:15 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*mem;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_calloc(1, 1));
	if (s_len < len)
		len = s_len;
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
