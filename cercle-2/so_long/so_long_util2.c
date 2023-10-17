/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:51:54 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/24 11:57:56 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_tmp;
	const char	*src_tmp;

	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dest_tmp = (char *)dst;
	src_tmp = (const char *)src;
	while (n--)
		dest_tmp[n] = src_tmp[n];
	return (dst);
}

char	*ft_str_free(char *line, char *map)
{
	free(line);
	free(map);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*read_map(int fd)
{
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	if (!map)
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (!tmp)
			break ;
		map = ft_strjoin(map, tmp);
		tmp = get_next_line(fd);
		free(tmp);
	}
	close(fd);
	if (!*map)
	{
		throw_error("Map is empty");
		free(map);
		return (NULL);
	}
	return (map);
}
