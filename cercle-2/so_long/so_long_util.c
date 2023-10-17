/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:30:07 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/28 15:01:42 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		mlx_destroy_exit(game);
	return (0);
}

void	game_init(t_game *game)
{
	int	img_width;
	int	img_height;

	game->collected = 0;
	game->cnt = 0;
	game->collect_cnt = 0;
	game->mlx = mlx_init();
	game->tile = mlx_xpm_file_to_image(game->mlx,
			"./images/floor50.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./images/wall50.xpm", &img_width, &img_height);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./images/coin1.xpm", &img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./images/door50.xpm", &img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./images/perso50.xpm", &img_width, &img_height);
}

size_t	ft_strlen_newline(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\n')
		count++;
	return (count);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
