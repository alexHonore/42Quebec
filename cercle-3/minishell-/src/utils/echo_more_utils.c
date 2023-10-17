/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:48:53 by jvillefr          #+#    #+#             */
/*   Updated: 2023/10/12 11:11:03 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

char	*take_off_first_el(char *s)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[size - 1] = '\0';
	return (s);
}

char	*put_status(char *str)
{
	char	*s;
	char	*new;

	new = NULL;
	new = ft_itoa(g_status);
	if (ft_strlen(str) > 1)
	{
		s = take_off_first_el(str);
		new = ft_strjoin(new, s);
	}
	return (new);
}

void	re_arrange_table_more(t_state *state, char **table, char c, int *num)
{
	while (table[num[4]])
	{
		if (table[num[4]][0] == '?')
		{
			table[num[4]] = put_status(table[num[4]]);
			num[3] += ft_strlen(table[num[4]]);
			num[4]++;
		}
		else if (c != '$' && num[4] == 0)
		{
			num[3] += ft_strlen(table[num[4]]);
			num[4]++;
		}
		else
		{
			table[num[4]] = ft_modif(table[num[4]], state->g_env,
					ft_is_delete(state, num, table[num[4]]));
			num[3] += ft_strlen(table[num[4]]);
			num[4]++;
		}
	}
}

void	re_arrange_table_double(t_state *state, char **s, int *num)
{
	int		i;
	int		j;
	char	**table;

	i = -1;
	while (s[++i])
	{
		if (count_dollar(s[i]) >= 1)
		{
			table = ft_split(s[i], '$');
			j = ft_strlen(s[i]);
			re_arrange_table_more(state, table, s[i][0], num);
			s[i] = ft_calloc(sizeof(char), num[3] + 1);
			ft_var_to_val_mor(s[i], table, num[4]);
			if (s[i][j - 1] == '$')
				s[i] = ft_strjoin(s[i], "$");
			num[3] = 0;
			num[4] = 0;
			free(table);
		}
	}
}

char	*re_arrange_table(t_state *state, char *s, int *num)
{
	char	**table;
	char	*new;
	int		l;

	table = ft_split(s, '$');
	l = ft_strlen(s);
	re_arrange_table_more(state, table, s[0], num);
	new = ft_calloc(sizeof(char), num[3] + 1);
	ft_var_to_val_mor(new, table, num[4]);
	if (s[l - 1] == '$')
		new = ft_strjoin(new, "$");
	ft_free(table);
	return (new);
}
