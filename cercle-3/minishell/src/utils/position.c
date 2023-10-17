/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:30:38 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 12:26:40 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_position_in_token(t_node *list, char *str, int n_pipe, int *start)
{
	t_node	*aff;
	int		pipe;
	int		i;

	pipe = 0;
	i = 0;
	aff = ft_get_first_node(list);
	while (aff)
	{
		if (pipe == n_pipe && ft_strncmp(aff->content, str,
				ft_strlen(aff->content)) == 0 && i > *start)
			return (i);
		else if (ft_strncmp(aff->content, "|\0", 2) == 0)
			pipe++;
		i++;
		aff = aff->next;
	}
	return (-1);
}
