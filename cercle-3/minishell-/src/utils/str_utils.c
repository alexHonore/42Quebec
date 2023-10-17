/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:04:46 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 11:36:09 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strchr_get_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

void	ft_str_to_str(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src || !dst)
	{
		return ;
	}
	i = ft_strlen(dst);
	while (src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
}

int	ft_str_in_str(char *str, char *find)
{
	int	i;
	int	i_save;
	int	j;

	i = 0;
	j = 0;
	i_save = 0;
	if (!find)
		return (-1);
	while (str[i])
	{
		j = 0;
		i_save = i;
		while (find[j] && str[i] == find[j])
		{
			if (!find[j + 1] && find[j] != str[i + 1])
				return (i_save);
			j++;
			i++;
		}
		i = i_save;
		i++;
	}
	return (-1);
}

int	ft_str_len_node(t_node *list)
{
	t_node	*token;
	int		i;

	i = -1;
	token = ft_get_first_node(list);
	while (token)
	{
		i++;
		token = token->next;
	}
	return (i);
}
