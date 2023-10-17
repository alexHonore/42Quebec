/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:53:42 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 16:25:00 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_space(char *line)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	j = 0;
	size = ft_strlen(line);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			j++;
		i++;
	}
	if (j == size)
		return (1);
	else
		return (0);
}

int	ft_str_size(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	done(t_state *state)
{
	ft_free_str_table(state->g_env);
	rl_clear_history();
	exit(state->error);
}

void	ft_var_to_val_mor(char *new, char **table, int i)
{
	int		j;

	j = -1;
	while (++j < i)
	{
		ft_str_to_str(new, table[j]);
		ft_free(table[j]);
	}
}

void	skip_tab(char *s)
{
	size_t	start;
	size_t	size;

	if (s != NULL && (s[0] == '\t' || s[0] == ' '))
	{
		size = ft_strlen(s);
		start = 1;
		while (start < size && (s[start] == '\t' || s[start] == ' '))
			start++;
		ft_memmove(s, s + start, size - start + 1);
	}
}
