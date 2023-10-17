/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:10:04 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/14 12:06:43 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c, int fd);
int		ft_print_u_nbr(unsigned int n);
int		ft_address2(unsigned long long num);
int		ft_hex_len(unsigned long num);
void	ft_pointer(unsigned long num);
int		ft_puthexadecimal(unsigned int n, const char c);
int		ft_printnbr(int n);
int		ft_printstr(char *s, int fd);

#endif