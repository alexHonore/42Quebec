/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:29:35 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:01:25 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	flood fill recursion
void	count_map_reachable_elements(t_game *game, int x, int y)
{
	if (game->flood_fill_map[x][y] == '1')
		return ;
	if (game->flood_fill_map[x][y] == 'E')
		game->reachable_exits_count++;
	if (game->flood_fill_map[x][y] == 'C')
		game->reachable_collectibles_count++;
	game->flood_fill_map[x][y] = '1';
	count_map_reachable_elements(game, x + 1, y);
	count_map_reachable_elements(game, x - 1, y);
	count_map_reachable_elements(game, x, y + 1);
	count_map_reachable_elements(game, x, y - 1);
}

/*
	count_map_reachable_elements :	Will recurcive the [game->flood_fill_map] 
									unless a wall(1) is there and count the collectibles and exits
	Then, it will compare it to the number of 
	collectibles and exits initially counted (without wall(1) restriction)
*/
int	has_valid_path(t_game *game, int x, int y)
{
	count_map_reachable_elements(game, x, y);
	if (game->collectibles_count != game->reachable_collectibles_count)
	{
		throw_error("Map must contain a valid path");
		return (0);
	}
	if (game->exits_count != game->reachable_exits_count)
	{
		throw_error("Map must contain a valid path");
		return (0);
	}
	return (1);
}

char	*check_map_lines(char **line, t_check *check, char **map, int fd)
{
	char	*lastline;

	while (*line)
	{
		if (is_not_rectangular(*line, check->len) || is_invalid_line(*line))
			return (ft_str_free(*line, *map));
		lastline = ft_strndup(*line, check->len);
		free(*line);
		*line = get_next_line(fd);
		if (*line)
			*map = ft_strjoin(*map, *line);
		else if (last_line_not_full_walls(lastline, check->len))
			return (ft_str_free(*line, *map));
		free(lastline);
	}
	return (0);
}

/*
	check_map_lines 	:	Exists only for norminette reasons,
							loop the map and stores it in [char* map]
							if the map is valid.
	has_valid_path 		:	Uses recursion to find is the [game->two_d_map] 
							is solvable based on the P(player) 
							position stored in the struct [game] 
	count_map_elements	:	count the nb of C and E, also,
							position the player through x,y variables
*/
char	*check_map(int fd, t_game *game)
{
	char	*map;
	char	*line;
	t_check	check;

	check_init(&check);
	line = get_next_line(fd);
	check.len = ft_strlen(line);
	map = ft_strndup(line, check.len);
	if (line_not_full_walls(line, check.len))
		return (ft_str_free(line, map));
	check_map_lines(&line, &check, &map, fd);
	game->two_d_map = ft_split(map, '\n');
	game->flood_fill_map = ft_split(map, '\n');
	count_map_elements(game);
	has_valid_path(game, game->x, game->y);
	return (check_cep(game, map));
}
