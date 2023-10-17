/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:29:50 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/27 15:07:06 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_game *game, int y, int x)
{
	if (game->two_d_map[y][x] == '0')
		return (1);
	if (game->two_d_map[y][x] == 'P')
		return (1);
	if (game->two_d_map[y][x] == 'C')
	{
		game->collected++;
		game->two_d_map[y][x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->tile, x * 64, y
			* 64);
		return (1);
	}
	if (game->two_d_map[y][x] == 'E' && game->collected == game->collect_cnt)
	{
		ft_printf("You finished the game in %d steps\n", game->cnt);
		mlx_destroy_exit(game);
	}
	return (0);
}

void	move_w(t_game *game)
{
	if (move_check(game, game->y - 1, game->x))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tile, game->x * 64,
			game->y * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x
			* 64, (game->y - 1) * 64);
		game->y--;
		ft_printf("Movement count: %d\n", ++game->cnt);
	}
}

void	move_s(t_game *game)
{
	if (move_check(game, game->y + 1, game->x))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tile, game->x * 64,
			game->y * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x
			* 64, (game->y + 1) * 64);
		game->y++;
		ft_printf("Movement count: %d\n", ++game->cnt);
	}
}

void	move_a(t_game *game)
{
	if (move_check(game, game->y, game->x - 1))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tile, game->x * 64,
			game->y * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->player, (game->x
				- 1) * 64, game->y * 64);
		game->x--;
		ft_printf("Movement count: %d\n", ++game->cnt);
	}
}

void	move_d(t_game *game)
{
	if (move_check(game, game->y, game->x + 1))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tile, game->x * 64,
			game->y * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->player, (game->x
				+ 1) * 64, game->y * 64);
		game->x++;
		ft_printf("Movement count: %d\n", ++game->cnt);
	}
}
