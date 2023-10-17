/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:48:53 by jvillefr          #+#    #+#             */
/*   Updated: 2023/10/12 16:59:33 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_double_sign_away(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1] && str[i] == '$')
		{
			str[i] = '\v';
			str[i + 1] = '\v';
			i++;
		}
		i++;
	}
}

int	count_dollar(char *str)
{
	int		occ;
	int		i;

	i = 0;
	occ = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '$')
			{
				i++;
				occ = 0;
			}
			else
			{
				i++;
				occ++;
			}
		}
		i++;
	}
	return (occ);
}

int	count_double_dollar(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1] && str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	ft_sigint_handler_more(int signum)
{
	(void)signum;
	printf("Quit: 3\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_handle_heredoc(int signum)
{
	(void)signum;
	ioctl(0, TIOCSTI, "\n");
	g_status = 256;
}
