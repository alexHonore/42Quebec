/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:20:55 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:31 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

int	throw_error(char *error, int exit_code)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\n%s\n", error);
	ft_printf("\033[0m");
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}

int	throw_error_detail(char *error, char *error_msg, int exit_code)
{
	printf("\033[0;31m\n");
	printf("Error\n%s\n", error);
	if (error_msg)
		printf("-> [%s]\n", error_msg);
	printf("\033[0m");
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}
