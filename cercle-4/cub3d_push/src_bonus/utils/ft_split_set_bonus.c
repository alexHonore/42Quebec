/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:21:51 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/07 13:26:13 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	ft_nb_split(const char *str, const char *set)
{
	char	*trimmed_str;
	int		nb;
	int		i;

	trimmed_str = ft_strtrim(str, set);
	if (!trimmed_str)
		return (-1);
	nb = 0;
	i = 0;
	if (!ft_strchr(set, trimmed_str[i]))
		nb++;
	while (trimmed_str[i])
	{
		if (ft_strchr(set, trimmed_str[i]) != NULL)
			nb++;
		i++;
	}
	free(trimmed_str);
	return (nb);
}

static size_t	get_element_size(char *str, char *set)
{
	size_t	size;

	size = 0;
	while (*str && ft_strchr(set, *str) == NULL)
	{
		size++;
		str++;
	}
	return (size);
}

char	**ft_split_set(char *str, char *set)
{
	char	**arr;
	int		arr_len;
	int		i;
	int		j;

	if (str == NULL || set == NULL)
		return (NULL);
	arr_len = ft_nb_split(str, set);
	arr = ft_calloc(arr_len + 1, sizeof(*arr));
	i = -1;
	while (++i < arr_len && *str)
	{
		while (*str && ft_strchr(set, *str) != NULL)
			str++;
		arr[i] = ft_calloc(get_element_size(str, set) + 1, sizeof(*arr[i]));
		if (!arr[i])
		{
			ft_free_str_array(arr);
			return (NULL);
		}
		j = 0;
		while (*str && ft_strchr(set, *str) == NULL)
			arr[i][j++] = *str++;
	}
	return (arr);
}
