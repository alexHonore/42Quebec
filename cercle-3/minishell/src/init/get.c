/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:12:16 by anshimiy          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:44 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//	Allocate the space for the new genv. (optional) free the old genv.
char	**ft_get_env(char **old, int size, int free_old)
{
	char	**new;
	int		i;

	if (old == NULL)
		return (NULL);
	new = ft_calloc(sizeof(char *), (ft_arr_size(old) + size));
	if (!new)
		return (NULL);
	i = 0;
	while (old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	if (free_old > 0)
		ft_free_str_table(old);
	return (new);
}

/// @brief Return the number of commands sparated by pipes
/// @param list
/// @return
int	ft_get_nb_cmds_pipe(t_node *list)
{
	t_node	*token;
	int		i;

	i = 1;
	token = ft_get_first_node(list);
	while (token)
	{
		if (ft_strncmp(token->content, "|\0",
				2) == 0 || ft_strncmp(token->content, "||\0", 2) == 0)
			i++;
		token = token->next;
	}
	return (i);
}
