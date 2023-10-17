/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:11:08 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 16:09:24 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// todo

// Length of ray from current position to next x or y-side
// Delta distance calculation
// Calculate the x & y delta values
static void	delta_distance_calculation(t_raycaster_data *rc)
{
	if (rc->rdx == 0)
		rc->d_dist_x = 1e30;
	else
		rc->d_dist_x = fabs(1 / rc->rdx);
	if (rc->rdy == 0)
		rc->d_dist_y = 1e30;
	else
		rc->d_dist_y = fabs(1 / rc->rdy);
}

// Calculate steps and initial side distances
// ???
static void	step_calculation(t_raycaster_data *rc)
{
	if (rc->rdx < 0)
	{
		rc->step_x = -1;
		rc->s_dist_x = (rc->px - rc->map_x) * rc->d_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->s_dist_x = (rc->map_x + 1.0 - rc->px) * rc->d_dist_x;
	}
	if (rc->rdy < 0)
	{
		rc->step_y = -1;
		rc->s_dist_y = (rc->py - rc->map_y) * rc->d_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->s_dist_y = (rc->map_y + 1.0 - rc->py) * rc->d_dist_y;
	}
}

// DDA or "Digital Differential Analysis". DDA is a fast algorithm typically
// used on square grids to find which squares a line hits (for example to
// draw a line on a screen, which is a grid of square pixels).
// rc->side is set to 0 for vertical hit or 1 for horizontal hit.
// When it hits a wall the loop breaks.
// Lastly it calculates the distance to the wall. */
static void	dda(t_raycaster_data *rc)
{
	while (1)
	{
		if (rc->s_dist_x < rc->s_dist_y)
		{
			rc->s_dist_x += rc->d_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->s_dist_y += rc->d_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map[rc->map_y][rc->map_x] == 1)
			break ;
	}
	if (rc->side == 0)
		rc->pwd = (rc->s_dist_x - rc->d_dist_x);
	else
		rc->pwd = (rc->s_dist_y - rc->d_dist_y);
}

// First calculate the camera x position. Then calculate the ray direction
// and the map position. Then calculate the delta distance and the step size.
// Then do the DDA and calculate the distance to the wall.
// Then calculate the wall height and the start and end positions for the wall.
// Then calculate the step size and x position on the texture.
// Then draw the wall.

static void	cast_single_ray(t_raycaster_data *rc)
{
	rc->cx = 2 * rc->x / (double)rc->screen_width - 1;
	rc->rdx = rc->pdx + rc->cpx * rc->cx;
	rc->rdy = rc->pdy + rc->cpy * rc->cx;
	rc->map_x = (int)rc->px;
	rc->map_y = (int)rc->py;
	delta_distance_calculation(rc);
	step_calculation(rc);
	dda(rc);
	prepare_for_drawing(rc);
	prepare_for_texture(rc);
	draw_textured_walls(rc);
}

// Cast a ray for every x position on the screen.
void	raycast(t_raycaster_data *rc)
{
	rc->x = 0;
	while (rc->x < rc->screen_width)
	{
		cast_single_ray(rc);
		rc->x++;
	}
}
