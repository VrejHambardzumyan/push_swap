/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:54:07 by vhambard          #+#    #+#             */
/*   Updated: 2025/06/05 13:35:41 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*merge_arg(int argc, char *argv[])
{
	int		i;
	int		curr_len;
	char	*merged;

	if (validate_arguments(argc, argv) == 1)
		return (NULL);
	merged = malloc(calculate_total_length(argc, argv));
	if (!merged)
		return (NULL);
	merged[0] = '\0';
	i = 1;
	curr_len = 0;
	while (i < argc)
	{
		ft_strlcpy(merged + curr_len, argv[i], ft_strlen(argv[i]) + 1);
		curr_len += ft_strlen(argv[i]);
		if (i < argc - 1)
			merged[curr_len++] = ' ';
		i++;
	}
	merged[curr_len] = '\0';
	return (merged);
}
