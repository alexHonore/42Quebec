/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:30:01 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 14:45:32 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cnt_collect(char *map)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

void	ft_update(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tile, x * 64, y * 64);
	if (game->two_d_map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y
			* 64);
	else if (game->two_d_map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x * 64, y
			* 64);
	else if (game->two_d_map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 64, y
			* 64);
	else if (game->two_d_map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y
			* 64);
		game->x = x;
		game->y = y;
	}
}

int	ft_render(t_game *game, char *map)
{
	int	row;
	int	col;
	int	y;
	int	x;

	game->collect_cnt = cnt_collect(map);
	row = ft_strlen_newline(map) + 1;
	col = ft_strlen(map) / row--;
	game->win = mlx_new_window(game->mlx, row * 64, col * 64, "so_long");
	y = 0;
	mlx_clear_window(game->mlx, game->win);
	while (y < col)
	{
		x = 0;
		while (x < row)
		{
			ft_update(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
