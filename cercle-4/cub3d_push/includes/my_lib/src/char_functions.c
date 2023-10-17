/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:10:00 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:19 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

int	ft_printchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

// NULL = return 6 bcuz NULL=4 and the %s =
int	ft_printstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_printstr("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

void	ft_print_array(char **arr)
{
	int	i;

	i = 0;
	write(1, "[\n", 2);
	while (arr[i])
	{
		write(1, "\t", 1);
		ft_putnbr_fd(i, 2);
		write(1, " [", 2);
		write(1, arr[i], ft_strlen(arr[i]));
		write(1, "]\n", 2);
		i++;
	}
	write(1, "]\n", 2);
}

void	ft_print_int_array(int **arr, int max_size)
{
	int	i;
	int	j;

	i = 0;
	write(1, "[\n", 2);
	while (arr[i])
	{
		write(1, "\t[", 2);
		j = 0;
		while (arr[i][j] || j < max_size)
		{
			ft_putnbr_fd(arr[i][j], 1);
			j++;
		}
		write(1, "]\n", 2);
		i++;
	}
	write(1, "]\n", 2);
}
