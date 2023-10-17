/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:21:26 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/16 17:11:56 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	init_player_position(t_raycaster_data *rc, t_game_info *game_info)
{
	rc->px = (double)game_info->player_x + 0.5;
	rc->py = (double)game_info->player_y + 0.5;
	rc->pdx = 1;
	rc->pdy = 0;
	if (game_info->player_direction == 'N')
		rotate_player(rc, degree_to_radian(-90));
	else if (game_info->player_direction == 'E')
		rotate_player(rc, degree_to_radian(0));
	else if (game_info->player_direction == 'S')
		rotate_player(rc, degree_to_radian(90));
	else if (game_info->player_direction == 'W')
		rotate_player(rc, degree_to_radian(180));
}

/**
 * @brief  Defines the tile size based on the screen size and map size.
 * @note   The rest of the code is relative to this size.
 * 		   Default division(L.43/44): 4
 * @param  *rc:
 * @retval None
 */
static void	set_tile_size(t_raycaster_data *rc)
{
	int	tile_size_x;
	int	tile_size_y;

	tile_size_x = (rc->screen_width / 2) / rc->map_width;
	tile_size_y = (rc->screen_height / 2) / rc->map_height;
	if (tile_size_x < tile_size_y)
		rc->tile_size = tile_size_x;
	else
		rc->tile_size = tile_size_y;
	if (rc->tile_size < 3)
		rc->tile_size = -1;
}

static void	load_textures(t_raycaster_data *rc, t_game_info *game_info)
{
	rc->textures[0] = load_png(game_info->north_texture);
	rc->textures[1] = load_png(game_info->south_texture);
	rc->textures[2] = load_png(game_info->east_texture);
	rc->textures[3] = load_png(game_info->west_texture);
}

// 2560 × 1600; macbook
// 1600 900; imac
t_raycaster_data	init_raycaster_data(t_game_info *game_info)
{
	t_raycaster_data	rc;

	rc.floor_color = game_info->floor_color;
	rc.ceiling_color = game_info->ceiling_color;
	rc.screen_width = 1600;
	rc.screen_height = 900;
	rc.map_width = game_info->map_width;
	rc.map_height = game_info->map_height;
	rc.map = game_info->map;
	set_tile_size(&rc);
	rc.cpx = 0;
	rc.cpy = 0.5 * ((double)rc.screen_width / (double)rc.screen_height);
	init_player_position(&rc, game_info);
	rc.rdx = 0;
	rc.rdy = 0;
	rc.mspeed = 0.05;
	rc.rspeed = 0.05;
	rc.vertical_view = 0;
	load_textures(&rc, game_info);
	rc.mlx = mlx_init(rc.screen_width, rc.screen_height, "cub3D", true);
	if (!rc.mlx)
		throw_error("Failed to initialize mlx", 1);
	return (rc);
}
