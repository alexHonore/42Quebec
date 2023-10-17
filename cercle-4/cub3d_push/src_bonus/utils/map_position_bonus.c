/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:24:57 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/07 14:29:41 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief  Return the position of the map in the file_data
 * @note   TODO: make sure this function is valid and don't need more...
 * @param  file_data:
 * @retval
 */
int	ft_find_map_position(char **file_data)
{
	int	i;

	i = 0;
	while (file_data[i])
	{
		if (file_data[i][0] && ft_str_made_of_set(file_data[i], "\t 1"))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	map_in_bounds(int **map, int x, int y)
{
	if (x >= 0 && y >= 0 && map[y][x])
		return (1);
	return (-1);
}

/**
 * @brief  Checks if the block to be deleted in the view is valid
 * @note   if itss a wall that's not a border, it's valid
 * @todo   Instead of checking based on the minimap ray position,
 *         check based on the a raycaster for it
 * @param  *rc:
 * @param  to_remove_x:
 * @param  to_remove_y:
 * @retval 1 if invalid, 0 if valid
 */
int	block_forbidden(t_raycaster_data *rc, int to_remove_x, int to_remove_y)
{
	if (!to_remove_x || !to_remove_y || to_remove_x > rc->map_width - 2
		|| to_remove_y > rc->map_height - 2)
	{
		return (1);
	}
	else if (rc->map[to_remove_y + 1][to_remove_x] == 2 || rc->map[to_remove_y
		- 1][to_remove_x] == 2)
	{
		return (1);
	}
	else if (!map_in_bounds(rc->map, to_remove_x + 1, to_remove_y)
		|| rc->map[to_remove_y][to_remove_x + 1] == 2
		|| rc->map[to_remove_y][to_remove_x - 1] == 2)
	{
		return (1);
	}
	else
		return (0);
}
