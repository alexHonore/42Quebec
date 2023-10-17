/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:59:19 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:18:01 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief  Get the texture path value from the given to_find string
 * @note   to_find act as an id from: NO, EA, SO, WE
 * @param  **file_data:
 * @param  *to_find:
 * @retval
 */
char	*ft_get_texture_value(char **file_data, char *to_find)
{
	int		start;
	int		i;
	char	*texture_path;
	char	*temp;

	i = 0;
	while (file_data[i])
	{
		if (ft_strncmp(to_find, file_data[i], 3) == 0)
			break ;
		i++;
	}
	if (file_data[i] == 0)
		ft_texture_error_case(1);
	texture_path = ft_substr(file_data[i], 3, ft_strlen(file_data[i]) - 3);
	if (ft_char_in_str(texture_path, '.') == 0)
		ft_texture_error_case(2);
	temp = ft_strrchr(texture_path, '.');
	start = ft_strcmp(".png", temp);
	if (start != 0)
		ft_texture_error_case(3);
	return (texture_path);
}

/**
 * @brief  Look for non expected data in the file_data
 * @note   Only NO, EA, SO, WE, F, C are expected
 * @param  **file_data:
 * @param  *game_info:
 * @retval None
 */
void	ft_valid_map_data(char **file_data, t_game_info *game_info)
{
	int	i;
	int	invalid_data;

	i = 0;
	invalid_data = 0;
	while (file_data[i] && i < game_info->mapstart)
	{
		while (!file_data[i][0])
			i++;
		if (i >= game_info->mapstart)
			break ;
		if (ft_strncmp(file_data[i], "NO ", 3) != 0
			&& ft_strncmp(file_data[i], "EA ", 3) != 0
			&& ft_strncmp(file_data[i], "SO ", 3) != 0
			&& ft_strncmp(file_data[i], "WE ", 3) != 0
			&& ft_strncmp(file_data[i], "F ", 2) != 0
			&& ft_strncmp(file_data[i], "C ", 2) != 0)
			invalid_data = 1;
		i++;
	}
	if (invalid_data == 1)
		ft_texture_error_case(5);
}

/**
 * @brief  Check if there's another to_find occurence in the file_data
 * @note
 * @param  **file_data:
 * @param  *to_find:
 * @param  len:
 * @retval 0 if there's no duplicate, 1 if there's duplicate
 */
int	ft_has_duplicate(char **file_data, char *to_find, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file_data[i])
	{
		if (ft_strncmp(to_find, file_data[i], len) == 0)
			count++;
		i++;
	}
	if (count == 0)
		ft_texture_error_case(1);
	if (count > 1)
		return (1);
	return (0);
}

/**
 * @brief  Get the map position and check if there's invalid data
 * @note
 * @param  **file_data:
 * @param  *game_info:
 * @retval None
 */
void	ft_check_textures(char **file_data, t_game_info *game_info)
{
	game_info->mapstart = ft_find_map_position(file_data);
	if (game_info->mapstart == -1)
		ft_map_error_case(1);
	ft_valid_map_data(file_data, game_info);
	if (ft_has_duplicate(file_data, "NO ", 3) || ft_has_duplicate(file_data,
			"EA ", 3) || ft_has_duplicate(file_data, "SO ", 3)
		|| ft_has_duplicate(file_data, "WE ", 3) || ft_has_duplicate(file_data,
			"F ", 2) || ft_has_duplicate(file_data, "C ", 2))
		ft_texture_error_case(4);
}

/**
 * @brief  Parse/check the textures and put it in the game_info
 * @param  **file_data:
 * @param  *game_info:
 * @retval None
 */
void	ft_load_textures(char **file_data, t_game_info *game_info)
{
	ft_check_textures(file_data, game_info);
	game_info->north_texture = ft_get_texture_value(file_data, "NO ");
	game_info->south_texture = ft_get_texture_value(file_data, "SO ");
	game_info->east_texture = ft_get_texture_value(file_data, "EA ");
	game_info->west_texture = ft_get_texture_value(file_data, "WE ");
	game_info->ceiling_color = ft_get_color(file_data, "C ");
	game_info->floor_color = ft_get_color(file_data, "F ");
}
