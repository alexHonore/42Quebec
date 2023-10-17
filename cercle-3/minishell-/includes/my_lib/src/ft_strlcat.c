/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:48:41 by anshimiy          #+#    #+#             */
/*   Updated: 2023/05/24 13:52:42 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

/// @brief	Concatenates [src] to the end of [dst], 
///			the resulting string is null-terminated.
///			It appends at most [dstsize] - 1 characters 
///			from src to dst and guarantees 
///			that dst remains null-terminated. The function returns
///			the total length of the concatenated string.
/// @param dst 
/// @param src 
/// @param dstsize 
/// @return 
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dest_length + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= dstsize)
		dest_length = dstsize;
	return (dest_length + src_length);
}
