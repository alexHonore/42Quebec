/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:39:17 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:36 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*compare the current char with all chars around it to
make sure that it is a playable space*/

/**
 * @brief  Compare the current char with all chars around to see
 * 		   if it is playable(is surounded by 1 or 0)
 * @note   TODO: comment that
 * @param  **map:
 * @param  i:
 * @param  j:
 * @retval 1 if the space is playable(is surounded by 1 or 0),
	0 otherwise(if there is a hole or non valid char)
 */
int	ft_is_playable(char **map, int i, int j)
{
	int	x;
	int	y;

	if (j == (int)ft_strlen(map[i]) - 1)
		return (0);
	x = j - 1;
	y = i - 1;
	if (x == -1)
		return (0);
	while (y <= i + 1)
	{
		if (!map[y])
			return (0);
		while (x <= j + 1)
		{
			if (!map[y][x] || (map[y][x] != '0' && map[y][x] != '1'))
				return (0);
			x++;
		}
		x = j - 1;
		y++;
	}
	return (1);
}

// Used to have:
// if (file_data[i][j] == '0' && ft_is_playable(file_data, i, j) == 0)
// 	ft_map_error_case(3);
// After [ has_tab = 1; ] line
void	ft_valid_map(char **file_data, t_game_info *game_info)
{
	int	j;
	int	i;
	int	has_tab;

	i = game_info->mapstart;
	j = 0;
	has_tab = 0;
	while (file_data[i])
	{
		j = 0;
		while (file_data[i][j])
		{
			if (file_data[i][j] == '\t')
				has_tab = 1;
			j++;
		}
		i++;
	}
	if (has_tab == 1)
	{
		printf("Warning: The map contains tabs(\\t). \
				You may encounter some issues...\n");
		printf("You should replace tabs by spaces.\n");
	}
}

/**
 * @brief  Validate the player identifier and get it's coord.
 * @note
 * @param  **file_data:
 * @param  *game_info:
 * @retval None
 */
void	ft_get_player_coord(char **file_data, t_game_info *game_info)
{
	int	i;
	int	j;
	int	nb_players;

	i = game_info->mapstart;
	j = 0;
	nb_players = 0;
	while (file_data[i])
	{
		if (ft_str_made_one_set(file_data[i], "NSEW"))
		{
			j = (int)(ft_strchr_set(file_data[i], "NSEW") - file_data[i]);
			game_info->player_direction = file_data[i][j];
			game_info->player_x = j;
			game_info->player_y = i - game_info->mapstart;
			file_data[i][j] = '0';
			nb_players++;
			j = 0;
		}
		i++;
	}
	if (nb_players == 0 || nb_players > 1)
		ft_map_error_case(2);
}

/**
 * @brief
 * @note
 * @param  **file_data:
 * @param  *game_info:
 * @retval None
 */
void	ft_load_map(char **file_data, t_game_info *game_info)
{
	ft_get_player_coord(file_data, game_info);
	ft_valid_map(file_data, game_info);
	ft_create_int_map(file_data, game_info);
}
