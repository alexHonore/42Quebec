/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:03:56 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 17:02:14 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_find_env_position(char **envp, char *path)
{
	int	i;
	int	size;

	i = 0;
	size = ft_arr_size(envp);
	while (i < size && ft_strncmp(path, envp[i], ft_strlen(path)))
		i++;
	if (i == size)
		return (-1);
	return (i);
}

int	ft_delete_env_utils(t_state *state, char **env_name, int i)
{
	char	*str;
	int		position;

	str = ft_strjoin(env_name[i], "=");
	position = ft_find_env_position(state->g_env, str);
	ft_free(str);
	if (position < 0)
		return (-1);
	ft_free(state->g_env[position]);
	while (state->g_env[position + 1])
	{
		state->g_env[position] = state->g_env[position + 1];
		position++;
	}
	state->g_env[position] = 0;
	return (1);
}

int	ft_delete_env(t_state *state, char **env_name)
{
	int	i;

	if (!env_name[1])
		return (-1);
	i = 1;
	while (i < ft_arr_size(env_name))
	{
		ft_delete_env_utils(state, env_name, i);
		i++;
	}
	return (1);
}

int	ft_delete_env_for_cd(t_state *state, char **env_name)
{
	int	i;

	if (!env_name[1])
		return (-1);
	i = 1;
	while (i < ft_arr_size(env_name))
	{
		if (ft_delete_env_utils(state, env_name, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}
