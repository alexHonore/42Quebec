/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:35:28 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:57 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief  
 * @note   
 * @param  **map: 
 * @param  x: 
 * @param  y: 
 * @param  *game_info: 
 * @retval 0 if valid, 1 if '0' is exposed to void or sum funky value,
 * * 2 if out of bounds,
 * * 3 if '0' is exposed to void or sum funky value at a border
*/
int	is_zero_exposed(char **map, int x, int y, t_game_info *game_info)
{
	char	c;

	if (x < 0 || x >= game_info->map_width
		|| y < 0 || y >= game_info->map_height)
		return (2);
	c = map[y][x];
	if (c == '0' || c == '1')
		return (0);
	if (x - 1 < 0 || x + 1 >= game_info->map_width
		|| y - 1 < 0 || y + 1 >= game_info->map_height)
		return (3);
	return (1);
}

int	ft_exposure_check(char **map, int x, int y, t_game_info *game_info)
{
	if (!map[y][x])
		return (1);
	if (map[y][x] == '0') 
	{
		if (is_zero_exposed(map, x - 1, y, game_info)
			|| is_zero_exposed(map, x + 1, y, game_info)
			|| is_zero_exposed(map, x, y - 1, game_info)
			|| is_zero_exposed(map, x, y + 1, game_info))
		{
			if (is_zero_exposed(map, x - 1, y, game_info) == 1)
				printf("Error at: map[%d][%d] = %c\n", y, x - 1, map[y][x - 1]);
			if (is_zero_exposed(map, x + 1, y, game_info) == 1)
				printf("Error at: map[%d][%d] = %c\n", y, x + 1, map[y][x + 1]);
			if (is_zero_exposed(map, x, y - 1, game_info) == 1)
				printf("Error at: map[%d][%d] = %c\n", y - 1, x, map[y - 1][x]);
			if (is_zero_exposed(map, x, y + 1, game_info) == 1)
				printf("Error at: map[%d][%d] = %c\n", y + 1, x, map[y + 1][x]);
			return (throw_error("Map is not closed with ones", 1));
		}
	}
	else if (map[y][x] && (ft_char_in_str("NSEW10 \0", map[y][x]) == 0
			|| (map[y][x] >= 9 && map[y][x] <= 13)))
		return (throw_error_detail("Map has non-valid \
				identifier...", &map[y][x], 1));
	return (0);
}

int	flood_check(char **file_data, t_game_info *game_info)
{
	char	**map;
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	map = (char **)malloc(sizeof(char *) * (game_info->map_height + 1));
	if (!map)
		return (throw_error("Malloc failed", 1));
	map[game_info->map_height] = 0;
	while (++i < game_info->map_height)
		map[i] = ft_strdup(file_data[i + game_info->mapstart]);
	while (y < game_info->map_height && map[y])
	{
		x = 0;
		while (x < game_info->map_width && map[y][x])
		{
			ft_exposure_check(map, x, y, game_info);
			x++;
		}
		y++;
	}
	ft_free_str_array(map);
	return (0);
}
