/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:09:29 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:47 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_color_error_case(int error)
{
	if (error == 1)
		throw_error("Invalid color setup... \
                        Respect this rgb format: \"[F or C] R,G,B\"\n", 1);
	if (error == 2)
		throw_error("Invalid rgb value. Pick a number from 0 to 255...\n", 1);
	if (error == 3)
		throw_error("Invalid floor and/or ceiling identifier...\n", 1);
}

void	ft_file_error_case(int error)
{
	if (error == 1)
		throw_error("Please, put a .cub file...\n", 1);
	if (error == 2)
		throw_error("Unable to open the provided file...\n", 1);
	if (error == 3)
		throw_error("The .cub file is empty...\n", 1);
}

void	ft_map_error_case(int error)
{
	if (error == 1)
		throw_error("No map found in file. Make sure to put a map at the end.\n",
			1);
	if (error == 2)
		throw_error("The map has an invalid number of players...\n", 1);
	if (error == 3)
		throw_error("The map is not playable... \
                        Borders may not be set correctly.\n", 1);
}

void	ft_texture_error_case(int error)
{
	if (error == 1)
		throw_error("Identifiers missing from .cub file on texture(s).\n", 1);
	if (error == 2)
		throw_error("No file extension on texture(s).\n", 1);
	if (error == 3)
		throw_error("Incorrect file extension on texture(s).\n", 1);
	if (error == 4)
		throw_error("Some texture(s) and/or color(s) have the same value.\n",
			1);
	if (error == 5)
		throw_error("Error in the identiifiers, \
				make sure to put (NO,SO,EA,WE) and (F,C).\n", 1);
}
