/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_commands_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:53:42 by anshimiy          #+#    #+#             */
/*   Updated: 2023/05/24 13:48:02 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_cat_env_value(char **env, char *path, int plus)
{
	char	*new;

	new = ft_calloc(sizeof(char),
			ft_strlen(ft_find_env_value(env, path)) + plus + 1);
	ft_strlcat(new, ft_find_env_value(env, path),
		ft_strlen(ft_find_env_value(env, path))
		+ 1);
	return (new);
}

char	*ft_free_3_ret(char *to_free_1, char *to_free_2, char *to_free_3,
		char *to_return)
{
	if (to_free_1)
		ft_free(to_free_1);
	if (to_free_2)
		ft_free(to_free_2);
	if (to_free_3)
		ft_free(to_free_3);
	return (to_return);
}
