/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:07:44 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/07 14:49:57 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/**

 * @brief  Game hook called evey frames. Catch the movements of the
 			player and it will raycast and draw the updated view of the map.
 * @note
 * @param  *param:
 * @retval None
 */
void	game_loop(void *param)
{
	t_raycaster_data	*rc;

	rc = param;
	key_hook(rc);
	raycast(rc);
	draw_pointer(rc);
	draw_map(*rc);
}

void	special_key_hook2(mlx_key_data_t keydata, t_raycaster_data *rc,
							int abs_px, int abs_py)
{
	int					selected_x;
	int					selected_y;

	selected_x = abs_px + (int)round(rc->pdx);
	selected_y = abs_py + (int)round(rc->pdy);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_RELEASE)
	{
		selected_x = abs_px + (int)round(rc->pdx * 2);
		selected_y = abs_py + (int)round(rc->pdy * 2);
		rc->new_block = init_point(selected_x, selected_y);
		move_block(rc, rc->old_block, rc->new_block);
	}
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_REPEAT)
	{
		rc->floor_color = ft_pixel(
				rand() % 0xFF, rand() % 0xFF,
				rand() % 0xFF, rand() % 0xFF);
		rc->ceiling_color = ft_pixel(
				rand() % 0xFF, rand() % 0xFF,
				rand() % 0xFF, rand() % 0xFF);
		set_background(*rc);
	}
}

void	special_key_hook(mlx_key_data_t keydata, void *param)
{
	t_raycaster_data	*rc;
	int					selected_x;
	int					selected_y;
	int					abs_px;
	int					abs_py;

	rc = param;
	abs_px = (int)floor(rc->px);
	abs_py = (int)floor(rc->py);
	selected_x = abs_px + (int)round(rc->pdx);
	selected_y = abs_py + (int)round(rc->pdy);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
	{
		if (rc->map[selected_y][selected_x] == 1 && block_forbidden(rc,
				selected_x, selected_y) == 0)
			rc->old_block = init_point(selected_x, selected_y);
		else
			rc->old_block = init_point(-1, -1);
	}
	special_key_hook2(keydata, rc, abs_px, abs_py);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		remove_block(rc);
}

/**
 * @brief  Uses the game_info datas to initialize the screen(floor, ceiling,
			textures) + raycaster data & draw the minimap.
 * @note   Thanks to the Codam's MLX42
 * @param  *game_info:
 * @retval None
 */
void	cub3d(t_game_info *game_info)
{
	t_raycaster_data	rc;

	rc = init_raycaster_data(game_info);
	rc.background = new_image(rc.mlx, rc.screen_width, rc.screen_height);
	rc.screen = new_image(rc.mlx, rc.screen_width, rc.screen_height);
	if (rc.tile_size > 0)
		rc.minimap = new_image(rc.mlx, rc.map_width * rc.tile_size,
				rc.map_height * rc.tile_size);
	set_background(rc);
	raycast(&rc);
	draw_map(rc);
	image_to_window(rc.mlx, rc.background, 0, 0);
	image_to_window(rc.mlx, rc.screen, 0, 0);
	if (rc.tile_size > 0)
		image_to_window(rc.mlx, rc.minimap, 0, 0);
	mlx_loop_hook(rc.mlx, game_loop, &rc);
	mlx_key_hook(rc.mlx, special_key_hook, &rc);
	mlx_loop(rc.mlx);
	mlx_terminate(rc.mlx);
	mlx_delete_texture(rc.textures[0]);
	mlx_delete_texture(rc.textures[1]);
	mlx_delete_texture(rc.textures[2]);
	mlx_delete_texture(rc.textures[3]);
}
