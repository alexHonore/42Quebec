/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:39 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/14 12:11:58 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num, 1);
	free(num);
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		i;

	i = ft_nbr_len(n);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (0);
	num[i] = '\0';
	while (n != 0)
	{
		num[i - 1] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (num);
}

int	ft_print_u_nbr(unsigned int n)
{
	int		i;
	char	*nbr;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		nbr = ft_uitoa(n);
		i = ft_printstr(nbr, 1);
		free(nbr);
	}
	return (i);
}
