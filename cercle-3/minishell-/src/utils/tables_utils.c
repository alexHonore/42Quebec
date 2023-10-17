/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:04:41 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 14:10:42 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_arr_size(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

char	*ft_find_env_value(char **envp, char *path)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_arr_size(envp);
	j = ft_strlen(path);
	while (i < size && ft_strncmp(path, envp[i], j))
		i++;
	if (i == size)
		return (NULL);
	return (envp[i] + j);
}

int	ft_is_splitable(char c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '|')
	{
		return (1);
	}
	return (0);
}

char	*ft_trim_char(char *str, int ptr)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	while (str[i])
	{
		if (i != ptr)
			newstr[j++] = str[i];
		i++;
	}
	ft_free(str);
	return (newstr);
}
