/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:07:44 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/15 17:48:07 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	set_background(rc);
	raycast(&rc);
	image_to_window(rc.mlx, rc.background, 0, 0);
	image_to_window(rc.mlx, rc.screen, 0, 0);
	mlx_loop_hook(rc.mlx, game_loop, &rc);
	mlx_loop(rc.mlx);
	mlx_terminate(rc.mlx);
	mlx_delete_texture(rc.textures[0]);
	mlx_delete_texture(rc.textures[1]);
	mlx_delete_texture(rc.textures[2]);
	mlx_delete_texture(rc.textures[3]);
}
