/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:10:00 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/11 16:10:02 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += ft_putchar_fd('-', fd);
		counter += ft_putchar_fd('2', fd);
		counter += ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		counter += ft_putchar_fd('-', fd);
		counter += ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		counter += ft_putchar_fd(n + '0', fd);
	}
	else
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	return (counter);
}

int ft_putchar_lower(char c, int fd)
{
    if (c >= 65 && c <= 90)
		c = c + 32;
	return write(fd, &c, 1);
}

int	ft_hexadecimal_upper(int n)
{
	static char	counter[100];
	int			remainder;

	int i, j = 0;
	while (n != 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			counter[j++] = 48 + remainder;
		else
			counter[j++] = 55 + remainder;
		n = n / 16;
	}
	i = j;
	while (i >= 0)
	{
		ft_putchar_fd(counter[i], 1);
		i--;
	}
	i++;
	return 0;
}


int ft_hexadecimal_lower(int n)
{
    static char counter[100];
    int remainder;
    int i, j = 0;

    while(n != 0)
    {
        remainder = n % 16;
        if (remainder < 10)
            counter[j++] = 48 + remainder;
        else
            counter[j++] = 55 + remainder;
        n = n / 16;
    }
    i = j;
    while(i >= 0)
    {
        ft_putchar_lower(counter[i], 1);
        i--;
    }
    i++;
    return 0;
}

int	ft_puthexadecimal(unsigned int n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_puthexadecimal(n * -1);
	}
	if (n < 10)
	{
		
        if ((n % 16) < 10)
			ft_putchar_fd((48 + (n % 16)), 1);
        else
			ft_putchar_fd((55 + (n % 16)), 1);
        //n = n / 16;
	}
	else
		ft_puthexadecimal(n / 16);
	ft_puthexadecimal(n % 16);

	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 16, fd);
	ft_putchar_fd(nbr % 16 + '0', fd);
}

int ft_putnbr_hexa(unsigned int c, int fd)
{
    return ft_putnbr_hexadecimal(c, fd);
}

long ft_pointer(long n)
{
    static char counter[10];
    long remainder;
    int i, j = 0;

    while(n != 0)
    {
        remainder = n % 16;
        if (remainder < 10)
            counter[j++] = 48 + remainder;
        else
            counter[j++] = 55 + remainder;
        n = n / 16;
    }
    i = j;
    while(i >= 0)
    {
        ft_putchar_lower(counter[i], 1);
        i--;
    }
    i++;
    return 0;
}

int ft_address(unsigned long num)
{
    char	*prefix;
    prefix = "0x";

    write(1, prefix, 2);
    ft_pointer(num);
    return 0;
}