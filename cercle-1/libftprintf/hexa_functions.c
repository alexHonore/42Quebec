/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:08:04 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/14 12:11:04 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int nbr, const char c)
{
	if (nbr >= 16)
	{
		ft_hexa(nbr / 16, c);
		ft_hexa(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			ft_printchar((nbr + '0'), 1);
		else if (c == 'x')
			ft_printchar((nbr - 10 + 'a'), 1);
		else if (c == 'X')
			ft_printchar((nbr - 10 + 'A'), 1);
	}
}

int	ft_puthexadecimal(unsigned int n, const char c)
{
	unsigned int	nbr;

	nbr = n;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(nbr, c);
	return (ft_hex_len(n));
}

void	ft_pointer(unsigned long num)
{
	if (num >= 16)
	{
		ft_pointer(num / 16);
		ft_pointer(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'), 1);
		else
			ft_printchar((num - 10 + 'a'), 1);
	}
}

int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_address2(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
	{
		ft_pointer(ptr);
		i += ft_hex_len(ptr);
	}
	return (i);
}
