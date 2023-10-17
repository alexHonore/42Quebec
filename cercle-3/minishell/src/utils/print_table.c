/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:24:00 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 11:33:52 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief Print a str array
/// @param str -> the value to print
/// @param new_line -> if 0, print without nl(\n), if 1,
///	print a nl(\n) between each values, if 2, a nl(\n) at the end only
void	ft_print_table(char **str, int new_line)
{
	int	i;
	int	size;

	i = 0;
	if (!str || !str[0])
		return ;
	size = ft_arr_size(str);
	while (str[i])
	{
		if (new_line == 1)
			printf("%s\n", str[i]);
		else
		{
			if (i == 0)
				printf("%s", str[i]);
			else if (i == size - 1)
				printf(" %s", str[i]);
			else
				printf(" %s", str[i]);
		}
		i++;
	}
	if (new_line == 2)
		printf("\n");
}
