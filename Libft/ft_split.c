/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:07:52 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/03 16:42:45 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char ch, char const *separators)
{
	int	i;

	i = 0;
	while (separators[i])
	{
		if (ch == separators[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*getword(char const *s, char const *separators)
{
	size_t	len;
	char	*res;
	size_t	i;

	len = 0;
	while (s[len] && !is_separator(s[len], separators))
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

static size_t	getcount(char const *s, char const *separators)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_separator(*s, separators))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static void	*makefree(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char const *separators)
{
	size_t	count;
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	count = getcount(s, separators);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && is_separator(*s, separators))
			s++;
		res[i] = getword(s, separators);
		if (!res[i])
			return (makefree(res, i));
		while (*s && !is_separator(*s, separators))
			s++;
		i++;
	}
	res[count] = NULL;
	return (res);
}
