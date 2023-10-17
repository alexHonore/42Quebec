/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:10:41 by anshimiy          #+#    #+#             */
/*   Updated: 2022/10/28 17:31:47 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

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
