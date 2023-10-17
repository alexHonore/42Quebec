/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:21:44 by anshimiy          #+#    #+#             */
/*   Updated: 2023/08/31 13:53:05 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_env_export_check(char *str, t_state *state)
{
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
	{
		ft_minishell_err(state, M_EXPORT_ERR, N_EXPORT_ERR);
		return (1);
	}
	return (0);
}

int	ft_find_env_index(char **envp, char *path)
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

void	ft_env_export_plus(t_state *state, char *temp, char *str, int size)
{
	char	*temp2;
	char	*join;

	temp2 = ft_find_env_value(state->g_env, temp);
	join = ft_strjoin(temp2, str);
	ft_free(str);
	ft_free(temp2);
	str = join;
	size = ft_find_env_index(state->g_env, temp);
	state->g_env[size] = ft_free(state->g_env[size]);
}

int	ft_env_export_procces(t_state *state, char *temp, char *str, int size)
{
	if (ft_find_env_value(state->g_env, temp))
	{
		if (ft_strchr_get_i(str, '=') > 0 && str[ft_strchr_get_i(str, '=')
				- 1] == '+')
			ft_env_export_plus(state, temp, str, size);
		else
		{
			size = ft_find_env_index(state->g_env, temp);
			state->g_env[size] = ft_free(state->g_env[size]);
		}
	}
	else
	{
		size = ft_arr_size(state->g_env);
		state->g_env = ft_get_env(state->g_env, 2, 1);
	}
	return (size);
}

void	ft_env_export(t_state *state, char *str, int check)
{
	char	*temp;
	int		size;
	int		len;
	int		i;

	i = 0;
	size = 0;
	if (check == 1 && (ft_env_export_check(str, state) == 1
			|| ft_strchr(str, '=') == NULL))
		return ;
	len = ft_strlen(str);
	temp = ft_calloc(sizeof(char), len + 1);
	while (str[i] && str[i] != '=')
	{
		temp[i] = str[i];
		i++;
	}
	size = ft_env_export_procces(state, temp, str, size);
	state->g_env[size] = ft_strdup(str);
	ft_free(temp);
}
