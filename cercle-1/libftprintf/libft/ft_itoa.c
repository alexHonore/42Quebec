/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:52:35 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/05 14:15:12 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_nb_to_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_intlen(long int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	char	*nbr;

	minus = 1;
	if (n < 0)
		minus = -1;
	len = ft_intlen(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	len--;
	while (len >= 0)
	{
		nbr[len] = ft_nb_to_abs(n % 10) + 48;
		n = ft_nb_to_abs(n / 10);
		len--;
	}
	if (minus == -1)
		nbr[0] = '-';
	return (nbr);
}
