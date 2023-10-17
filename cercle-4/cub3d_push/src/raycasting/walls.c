/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:09:13 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/16 17:22:42 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// todo

// Calculate wall height, draw start and end positions for the wall.
// Calculate the step size and x position on the texture.
void	prepare_for_drawing(t_raycaster_data *rc)
{
	rc->line_height = (int)(rc->screen_height / rc->pwd);
	rc->draw_start = -rc->line_height / 2 + rc->screen_height / 2
		+ rc->vertical_view;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + rc->screen_height / 2
		+ rc->vertical_view;
	if (rc->draw_end >= rc->screen_height)
		rc->draw_end = rc->screen_height - 1;
	if (rc->side == 0)
		rc->wall_x = rc->py + rc->pwd * rc->rdy;
	else
		rc->wall_x = rc->px + rc->pwd * rc->rdx;
	rc->wall_x -= floor((rc->wall_x));
}

// Set the texture to use for the wall depending on the orientation(N,S,E,W).
// Then set the x position on the texture.
// static void	prepare_for_texture(t_raycaster_data *rc)
/**
 * @brief  
 * @note   rc->side == 1 && rc->rdy < 0: NORTH
 *		   rc->side == 1 && rc->rdy > 0: SOUTH
 * 		   rc->side == 0 && rc->rdx > 0: EAST
 * 		   rc->side == 0 && rc->rdx < 0: WEST
 * @param  *rc: 
 * @retval None
*/
void	prepare_for_texture(t_raycaster_data *rc)
{
	if (rc->side == 0 && rc->rdx < 0)
		rc->tex_num = 0;
	if (rc->side == 0 && rc->rdx > 0)
		rc->tex_num = 1;
	if (rc->side == 1 && rc->rdy < 0)
		rc->tex_num = 2;
	if (rc->side == 1 && rc->rdy > 0)
		rc->tex_num = 3;
	rc->tex = rc->textures[rc->tex_num];
	rc->tex_x = (int)(rc->wall_x * (double)(rc->tex->width));
	if (rc->side == 0 && rc->rdx > 0)
		rc->tex_x = rc->tex->width - rc->tex_x - 1;
	if (rc->side == 1 && rc->rdy < 0)
		rc->tex_x = rc->tex->width - rc->tex_x - 1;
	rc->tex_step = (double)rc->tex->height / (double)rc->line_height;
	rc->tex_pos = (rc->draw_start - rc->vertical_view - rc->screen_height / 2
			+ rc->line_height / 2) * rc->tex_step;
}

int32_t	get_texture_color(u_int8_t *pixel)
{
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

// Draws the walls on the screen image.
void	draw_textured_walls(t_raycaster_data *rc)
{
	rc->y = 0;
	while (rc->y < rc->draw_start)
	{
		put_pixel(rc->screen, rc->x, rc->y, TRANSPARENT);
		rc->y++;
	}
	while (rc->y < rc->draw_end)
	{
		rc->tex_y = (int)rc->tex_pos;
		rc->tex_pos += rc->tex_step;
		rc->color = get_texture_color(&rc->tex->pixels[(rc->tex->width
					* rc->tex_y + (rc->tex->width - rc->tex_x - 1)) * 4]);
		put_pixel(rc->screen, rc->x, rc->y, rc->color);
		rc->y++;
	}
	while (rc->y < rc->screen_height)
	{
		put_pixel(rc->screen, rc->x, rc->y, TRANSPARENT);
		rc->y++;
	}
}
