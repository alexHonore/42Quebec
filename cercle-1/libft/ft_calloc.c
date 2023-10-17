/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:10:41 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/22 11:58:43 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	array = malloc(count * size);
	if (!array)
		return (array);
	ft_bzero(array, (count * size));
	return (array);
}
