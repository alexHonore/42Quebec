/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:29:41 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:02:48 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_invalid_char(char c)
{
	if (c == '\n')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'P')
		return (0);
	else
		return (1);
}

int	is_invalid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_invalid_char(line[i]))
		{
			throw_error("Map has non-valid char, Only P/C/E/0/1.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_close(char *line, size_t len)
{
	if (line[0] == '1' && line[len - 2] == '1')
		return (0);
	else
		return (1);
}

int	is_not_rectangular(char *line, size_t len)
{
	if (len != ft_strlen(line) || check_close(line, len))
	{
		throw_error("Map must be rectangular.\n");
		return (1);
	}
	return (0);
}

char	*check_cep(t_game *game, char *map)
{
	if (game->player_count == 0 || game->exits_count == 0
		|| game->collectibles_count == 0)
	{
		throw_error("Map must have at least one C/E/P each.\n");
		free(map);
		return (NULL);
	}
	return (map);
}
