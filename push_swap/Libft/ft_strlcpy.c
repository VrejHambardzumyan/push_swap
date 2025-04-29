/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:20:32 by vhambard          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:55 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len ++;
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return (src_len);
}
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
////  char src1[] = "Hello, World!";
//   char dst1[20];
//
//    size_t len1 = ft_strlcpy(dst1, src1, sizeof(dst1));
//
//    printf("Test 1:\n");
//    printf("Source: %s\n", src1);
//    printf("Destination: %s\n", dst1);
//    printf("Returned Length: %zu\n\n", len1); 
//
//   char dst2[6]; 
//    size_t len2 = ft_strlcpy(dst2, src1, sizeof(dst2));
//
//    printf("Test 2:\n");
//    printf("Source: %s\n", src1);
//    printf("Destination: %s\n", dst2);
//    printf("Returned Length: %zu\n\n", len2);
//
//    char dst3[10];
//    size_t len3 = ft_strlcpy(dst3, src1, 0);
//
//    printf("Test 3:\n");
//    printf("Returned Length: %zu (Destination not modified)\n\n", len3); 
//
//    char src4[] = "";
//   char dst4[10];
//
//   size_t len4 = ft_strlcpy(dst4, src4, sizeof(dst4));
//
//    printf("Test 4:\n");
//    printf("Source: \"%s\"\n", src4);
//    printf("Destination: \"%s\"\n", dst4);
//    printf("Returned Length: %zu\n\n", len4); 
//}
