/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:11:33 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/07 14:22:18 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief
 * @note
 * @param  *rc:
 * @param  rot:
 * @retval None
 */
void	rotate_player(t_raycaster_data *rc, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = rc->pdx;
	rc->pdx = rc->pdx * cos(rot) - rc->pdy * sin(rot);
	rc->pdy = old_dir_x * sin(rot) + rc->pdy * cos(rot);
	old_plane_x = rc->cpx;
	rc->cpx = rc->cpx * cos(rot) - rc->cpy * sin(rot);
	rc->cpy = old_plane_x * sin(rot) + rc->cpy * cos(rot);
}

/**
 * @brief  If the change is in the limits of the screen/not in a wall,
	it changes the horizontal view and update the background/angles
 * @note
 * @param  *rc:
 * @param  move_x:
 * @param  move_y:
 * @retval None
 */
static void	move_player(t_raycaster_data *rc, double move_x, double move_y)
{
	if (rc->map[(int)rc->py][(int)(rc->px + move_x)] == 0)
		rc->px += move_x;
	if (rc->map[(int)(rc->py + move_y)][(int)rc->px] == 0)
		rc->py += move_y;
}

void	key_hook(t_raycaster_data *rc)
{
	mlx_t	*mlx;
	double	move_x;
	double	move_y;

	mlx = rc->mlx;
	move_x = rc->mspeed * rc->pdx;
	move_y = rc->mspeed * rc->pdy;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		move_player(rc, move_x, move_y);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		move_player(rc, -move_x, -move_y);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move_player(rc, move_y, -move_x);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_player(rc, -move_y, move_x);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		rotate_player(rc, -rc->rspeed);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_E))
		rotate_player(rc, rc->rspeed);
}
