/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:30:13 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:33 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_ext(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".ber", 4) != 0)
	{
		throw_error("Invalid file extension, make sure to have a .ber file");
		return (0);
	}
	return (1);
}

int	exit_game(t_game *game)
{
	free_game(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

/*
	check_map :	Do all the parsing of the given map and 
				if good, return an array of the map data
	game_init :	Simply initialize the game struct
	ft_render :	Display the window and ensure that each 
				movement made is graphically updated
*/
int	main(int argc, char **argv)
{
	t_game	game;
	char	*map;
	int		fd;

	if (argc != 2)
		ft_error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(0);
	if (!is_valid_ext(argv[1]))
		ft_error(2);
	map = check_map(fd, &game);
	if (map == NULL)
		return (0);
	game_init(&game);
	ft_render(&game, map);
	free(map);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
