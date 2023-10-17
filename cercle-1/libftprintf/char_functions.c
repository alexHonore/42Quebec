/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:10:00 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/14 12:10:57 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_printstr(char *s, int fd)

// NULL = return 6 bcuz NULL=4 and the %s = 2
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
		ft_printchar(s[i], fd);
		i++;
	}
	return (i);
}
