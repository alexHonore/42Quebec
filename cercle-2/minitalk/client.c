/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:28:13 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/29 21:24:14 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib/mylib.h"
#include <signal.h>
#include <unistd.h>

//to send bit by bit a char
static void	ft_send_signal(char *str, pid_t pid)
{
	int	len;
	int	byte;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		byte = 8;
		while (byte)
		{
			byte--;
			if ((*str >> byte & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(75);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !argv)
	{
		ft_putendl_fd("Incorect arguments. Try: ./client <string>", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		ft_putendl_fd("You are trying to send empty string...", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1 || pid > 99998)
	{
		ft_putendl_fd("PID is invalid", 1);
		return (1);
	}
	ft_send_signal(argv[2], pid);
	return (0);
}
