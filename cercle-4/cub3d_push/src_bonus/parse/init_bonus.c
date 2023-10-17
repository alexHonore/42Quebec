/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:55:57 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 18:02:21 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief  Check if the file is valid and accesible
 * @note
 * @param  path: The path to the file
 * @retval None
 */
void	ft_is_valid_file(char *path)
{
	int		i;
	int		j;
	int		file_fd;
	char	*ext;
	char	*buffer;

	i = -1;
	j = 0;
	buffer = ft_calloc(2, sizeof(char));
	while (path[++i])
		if (path[i] == '.')
			j = i;
	if (j == 0)
		ft_file_error_case(1);
	ext = ft_substr(path, j, i);
	if (ft_strcmp(ext, ".cub") != 0)
		ft_file_error_case(1);
	file_fd = open(path, O_RDONLY);
	if (file_fd == -1)
		ft_file_error_case(2);
	if (read(file_fd, buffer, 1) == -1)
		ft_file_error_case(3);
	ft_free_two(ext, buffer);
	close(file_fd);
}

static void	ft_init_struct(t_game_info *game_info)
{
	game_info->floor_color = 0;
	game_info->ceiling_color = 0;
	game_info->north_texture = 0;
	game_info->east_texture = NULL;
	game_info->south_texture = NULL;
	game_info->west_texture = NULL;
	game_info->player_direction = 0;
	game_info->player_x = 0;
	game_info->player_y = 0;
	game_info->map_width = 0;
	game_info->map_height = 0;
	game_info->map = 0;
	game_info->mapstart = 0;
}

/**
 * @brief Initialize the game_info struct
 * @note
 * @param argv:
 * @retval The t_game_info struct
 */
t_game_info	*ft_init_game_info(char **argv)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)ft_calloc(1, sizeof(t_game_info));
	if (!game_info)
		throw_error("Malloc failed\n", 1);
	ft_init_struct(game_info);
	ft_is_valid_file(argv[1]);
	ft_parse_infos(argv[1], game_info);
	return (game_info);
}
