/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:54:44 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:29 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_init(t_check *check)
{
	check->collect = 0;
	check->exit = 0;
	check->player = 0;
}

int	line_not_full_walls(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (line[i] != '1')
		{
			write(1, "Error : map must be surrounded by walls.\n", 42);
			return (1);
		}
		i++;
	}
	return (0);
}

int	last_line_not_full_walls(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (line[i] != '1')
		{
			write(1, "Error : map must be surrounded by walls.\n", 42);
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

void	count_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->two_d_map[i])
	{
		j = 0;
		while (game->two_d_map[i][j])
		{
			if (game->two_d_map[i][j] == 'C')
				game->collectibles_count++;
			if (game->two_d_map[i][j] == 'E')
				game->exits_count++;
			if (game->two_d_map[i][j] == 'P')
			{
				game->player_count++;
				game->x = i;
				game->y = j;
			}
			j++;
		}
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}
