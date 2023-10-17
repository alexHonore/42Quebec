/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:25:11 by anshimiy          #+#    #+#             */
/*   Updated: 2023/05/23 11:42:18 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**ft_get_env_var_names(char **env)
{
	int		i;
	int		var_index;
	int		j;
	char	**new;
	char	*tmp;

	i = 0;
	var_index = 0;
	j = 0;
	new = ft_calloc(sizeof(char *), ft_arr_size(env) + 1);
	while (env[i])
	{
		var_index = ft_strchr_get_i(env[i], '=');
		tmp = ft_calloc(sizeof(char), var_index + 1);
		j = 0;
		while (j < var_index)
		{
			tmp[j] = env[i][j];
			j++;
		}
		new[i] = tmp;
		i++;
	}
	return (new);
}

void	ft_bubble_sort_str_array(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (i >= 1 && ft_strncmp(env[i], env[i - 1], ft_strlen(env[i])) < 0)
		{
			ft_swap_str(&env[i - 1], &env[i]);
			i = 0;
		}
		i++;
	}
}

int	ft_get_nb_alpha(char *str)
{
	int	i;
	int	letter;

	i = 0;
	letter = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
			letter++;
		i++;
	}
	return (letter);
}

void	ft_env_organized(char **env_original)
{
	int		i;
	char	*tmp;
	char	**env_names;

	i = 0;
	env_names = ft_get_env_var_names(env_original);
	ft_bubble_sort_str_array(env_names);
	i = 0;
	while (env_names[i])
	{
		if (ft_get_nb_alpha(env_names[i]) != 0)
		{
			tmp = ft_strjoin(env_names[i], "=");
			printf("declare -x %s=\"%s\"\n", env_names[i], ft_find_env_value(
					env_original, tmp));
			ft_free(tmp);
		}
		i++;
	}
	ft_free_str_table(env_names);
}

int	ft_add_env(t_state *state, char **past, int check)
{
	int	i;

	if (ft_arr_size(past) == 1)
	{
		ft_env_organized(state->g_env);
		return (1);
	}
	i = 1;
	while (i < ft_arr_size(past))
	{
		ft_env_export(state, past[i], check);
		i++;
	}
	return (1);
}
