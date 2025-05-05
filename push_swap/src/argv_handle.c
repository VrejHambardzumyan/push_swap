/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:19 by vhambard          #+#    #+#             */
/*   Updated: 2025/05/05 21:07:28 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	only_1_spaces(int argc, char **argv)
{
	int	len;
	int	i;
	int	in_word;
	int	j;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		in_word = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
			{
				len++;
				in_word = 1;
			}
			else if (in_word)
			{
				len++;
				in_word = 0;
			}
			j++;
		}
		if (in_word && i < argc - 1)
			len++;
		i++;
	}
	return (len + 1);
}

char	*merge_arg(int argc, char *argv[])
{
	int		total_len;
	int		i;
	int		j;
	int		k;
	int		in_word;
	char	*merged;

	in_word = 0;
	total_len = only_1_spaces(argc, argv);
	merged = (char *)malloc(total_len);
	if (!merged)
		return (NULL);
	merged[0] = '\0';
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
			{
				merged[k] = argv[i][j];
				in_word = 1;
			}
			else if (in_word)
			{
				merged[k++] = ' ';
				in_word = 0;
			}
			j++;
		}
		if (in_word && i < argc - 1)
			merged[k++] = ' ';
		i++;
	}
	if (k > 0 && merged[k - 1] == ' ')
		k--;
	merged[k] = '\0';
	return (merged);
}
