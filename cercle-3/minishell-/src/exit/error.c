/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:17:27 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/11 15:26:27 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	ft_update_g_status(void)
{
	if (g_status == 3)
		g_status = 131;
	else if (g_status == 2)
		g_status = 130;
	else if (g_status == 258)
		g_status = 258;
	else
	{
		g_status /= 256;
		if (g_status == 9)
			g_status = 127;
	}
}

void	ft_minishell_err(t_state *state, char *msg, int err)
{
	state->error = err;
	ft_putstr_fd(msg, 2);
}

void	min_shell_err(t_state *state, char *cmd, char *msg, int err)
{
	state->error = err;
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(state->cmds[state->index].cmd_args[1], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	err_mini(t_state *state, char *arg, char *msg_error, int err)
{
	state->error = err;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg_error, 2);
}

void	err_mini_exit(t_state *state, char *cmd, char *msg, int err)
{
	state->error = err;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
}
