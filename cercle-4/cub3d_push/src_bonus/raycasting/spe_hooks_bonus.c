/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:18:37 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/07 14:29:11 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// Replace a block (1) with a floor (0) in the map if it's not on the border.
void	move_block(t_raycaster_data *rc, t_point old_block, t_point new_block)
{
	if (block_forbidden(rc, new_block.x, new_block.y) == 0)
	{
		if (!(old_block.x == -1 || old_block.y == -1))
			rc->map[old_block.y][old_block.x] = 0;
		if (rc->map[new_block.y][new_block.x] == 0)
			rc->map[new_block.y][new_block.x] = 1;
	}
}

// Replace a block (1) with a floor (0) in the map if it's not on the border.
void	remove_block(t_raycaster_data *rc)
{
	int	abs_px;
	int	abs_py;
	int	to_remove_x;
	int	to_remove_y;

	abs_px = (int)floor(rc->px);
	abs_py = (int)floor(rc->py);
	to_remove_x = abs_px + (int)round(rc->pdx);
	to_remove_y = abs_py + (int)round(rc->pdy);
	if (block_forbidden(rc, to_remove_x, to_remove_y) == 0)
		rc->map[to_remove_y][to_remove_x] = 0;
	else
		return ;
}
