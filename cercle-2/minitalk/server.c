/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:28:17 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/30 14:55:55 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib/mylib.h"
#include <signal.h>
#include <unistd.h>

static void	ft_print_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				byte;

	(void)context;
	if (byte == 0)
		byte = 8;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	byte--;
	c += (sig & 1) << byte;
	if (byte == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		byte = 8;
		c = 0;
	}
}

/* The server must be started first. After its launch, it has to print its PID.
• The client takes two parameters:
	-The server PID.
 	-The string to send.
• The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
*/
int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Welcome, here's your PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_print_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
