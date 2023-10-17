/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:25:55 by anshimiy          #+#    #+#             */
/*   Updated: 2023/05/16 14:27:58 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}

void	**ft_free_str_table(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return (0);
	while (array[++i])
		if (array[i])
			array[i] = ft_free(array[i]);
	array = ft_free(array);
	return (0);
}
