/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:29:59 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:39 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief  Get the number of lines in the .cub file
 * @note
 * @param  path:
 * @retval
 */
int	ft_nb_lines(char *path)
{
	int		file_fd;
	char	*line;
	int		nb_lines;

	nb_lines = 0;
	file_fd = open(path, O_RDONLY);
	if (file_fd == -1)
		ft_file_error_case(2);
	line = get_next_line(file_fd);
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(file_fd);
	}
	if (nb_lines == 0)
		ft_file_error_case(3);
	free(line);
	close(file_fd);
	return (nb_lines);
}

/**
 * @brief  Get the map data from the file and store it in a 2D array
 * @note
 * @param  path:
 * @retval
 */
char	**ft_get_map_data(char *path)
{
	char	**file_data;
	char	*line;
	int		file_fd;
	int		i;

	i = 0;
	file_data = ft_calloc(ft_nb_lines(path) + 1, sizeof(char *));
	if (!file_data)
		throw_error("Unable to allocate memory for the map data...\n", 1);
	file_fd = open(path, O_RDONLY);
	if (!file_fd)
		ft_file_error_case(2);
	line = get_next_line(file_fd);
	while (line)
	{
		file_data[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(file_fd);
	}
	free(line);
	close(file_fd);
	file_data[i] = 0;
	return (file_data);
}

/**
 * @brief  Parse the proper values of the .cub file
 * @note
 * @param  path:
 * @param  *game_info:
 * @retval None
 */
void	ft_parse_infos(char *path, t_game_info *game_info)
{
	char	**file_data;

	(void)game_info;
	file_data = ft_get_map_data(path);
	ft_load_textures(file_data, game_info);
	ft_load_map(file_data, game_info);
	ft_free_str_array(file_data);
}
