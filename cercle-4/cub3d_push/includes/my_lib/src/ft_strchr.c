/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:12:49 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:21 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

/**
 * @brief  Locates the first occurrence of c
 * @note
 * @param  *s:
 * @param  c:
 * @retval return the pointer to the located character or NULL if not found
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

/**
 * @brief  Locates the first occurrence of any char from the *set
 * @note
 * @param  *str:
 * @param  *set:
 * @retval return the pointer to the located character or NULL if not found
 */
char	*ft_strchr_set(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_in_str((char *)set, str[i]))
			return ((char *)(str + i));
		i++;
	}
	if (!set)
		return ((char *)(str + i));
	return (NULL);
}

/**
 * @brief  If c is in *str, return 1, else return 0
 * @note   
 * @param  *str: 
 * @param  c: 
 * @retval 1 if c is in *str, if not 0
*/
int	ft_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief  Check if *str is made only of the chars from the *set
 * @note
 * @param  *str:
 * @param  *set:
 * @retval 0 if not made only of the chars from the *set,
	1 if made only of the chars from the *set
 */
int	ft_str_made_of_set(char *str, char *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				found = 1;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Check if *str has one char from the *set
 * @note
 * @param  *str:
 * @param  *set:
 * @retval 0 if no letter from the set was found, 1 if found
 */
int	ft_str_made_one_set(char *str, char *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				found = 1;
			j++;
		}
		i++;
	}
	return (found);
}
