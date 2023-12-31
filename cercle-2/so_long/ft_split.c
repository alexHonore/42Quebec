/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:28:27 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 14:08:37 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_cnt_ary(const char *s, char c)
{
	size_t	cnt;
	size_t	flag;

	cnt = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

static size_t	ft_cnt_wrd(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0' && *s != c)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

static char	*ft_strnndup(const char *s1, size_t n)
{
	char	*s2;
	char	*tmp;

	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (0);
	tmp = s2;
	while (n-- > 0)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (s2);
}

static void	ft_free(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wrd;
	size_t	ary;
	char	**split;

	ary = ft_cnt_ary(s, c);
	split = (char **)malloc(sizeof(char *) * (ary + 1));
	if (!split)
		return (0);
	i = -1;
	while (++i < ary)
	{
		while (*s != '\0' && *s == c)
			s++;
		wrd = ft_cnt_wrd(s, c);
		split[i] = ft_strnndup(s, wrd);
		if (!split[i])
		{
			ft_free(split, i - 1);
			return (0);
		}
		s += wrd;
	}
	split[i] = NULL;
	return (split);
}
