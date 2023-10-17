/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:14:48 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/16 17:03:07 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_info(t_game_info *game_info)
{
	ft_free(game_info->north_texture);
	ft_free(game_info->east_texture);
	ft_free(game_info->south_texture);
	ft_free(game_info->west_texture);
	ft_free_int_array(game_info->map, game_info->map_height);
	ft_free(game_info);
}

int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		throw_error("Invalid number of arguments. Type => ./cub3D [.cub file]\n",
			1);
	game_info = ft_init_game_info(argv);
	cub3d(game_info);
	free_info(game_info);
	exit(0);
	return (0);
}
