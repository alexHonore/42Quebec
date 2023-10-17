/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:16:46 by alexnshimiy       #+#    #+#             */
/*   Updated: 2023/10/12 19:17:52 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief  Look if it's a positive or negative slope x/y
 * @note
 * @param  *line_data:
 * @param  *p1:
 * @param  *p2:
 * @retval None
 */
void	lh_init(t_line_data *line_data, t_point *p1, t_point *p2)
{
	line_data->dx = abs(p2->x - p1->x);
	if (p1->x < p2->x)
		line_data->sx = 1;
	else
		line_data->sx = -1;
	line_data->dy = -abs(p2->y - p1->y);
	if (p1->y < p2->y)
		line_data->sy = 1;
	else
		line_data->sy = -1;
	line_data->err = line_data->dx + line_data->dy;
	line_data->x = p1->x;
	line_data->y = p1->y;
}

/**
 * @brief  Useful to create a rectangle and saving plenty of code lines.
 * @note   Take position and size of the rectangle then return the rectangle.
 * @param  x:
 * @param  y:
 * @param  width:
 * @param  height:
 * @retval
 */
t_rectangle	init_rectangle(int x, int y, int width, int height)
{
	t_rectangle	out;

	out.x = x;
	out.y = y;
	out.width = width;
	out.height = height;
	return (out);
}

/**
 * @brief  Useful to create a point and saving plenty of code lines.
 * @note   Take position then return the coord struct.
 * @param  x:
 * @param  y:
 * @retval
 */
t_point	init_point(int x, int y)
{
	t_point	out;

	out.x = x;
	out.y = y;
	return (out);
}
