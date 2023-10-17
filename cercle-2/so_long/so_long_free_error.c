/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:04:58 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:07 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->two_d_map[i++])
		free(game->two_d_map[i]);
	free(game->two_d_map);
	i = -1;
	while (game->flood_fill_map[i++])
		free(game->flood_fill_map[i]);
	free(game->flood_fill_map);
}

int	mlx_destroy_exit(t_game *game)
{
	free_game(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	ft_error(int exit_code)
{
	write(1, "Error", 6);
	if (exit_code == 0)
		write(1, ": Cannot open the map file.\n", 29);
	if (exit_code == 1)
		write(1, ": Please run with a map file.\n", 31);
	if (exit_code == 2)
		write(1, ": Please run with a .ber file.\n", 31);
	exit(exit_code);
}

int	throw_error(char *error)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\n%s\n", error);
	ft_printf("\033[0m");
	exit(1);
	return (1);
}
