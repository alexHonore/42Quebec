/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:21:31 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/11 15:26:00 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_status;

void	ft_process_cmd_fork(t_state *state)
{
	int		error;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		error = ft_execve(state);
		ft_minishell_err(state, M_EXECVE_ERR, N_EXECVE_ERR);
		g_status = error;
		exit(error);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &g_status, 0);
	}
}

void	ft_process_command(t_state *state)
{
	state->index = 0;
	if (state->error == 0)
	{
		ft_on_redirection(state);
		if (ft_run_builtin(state) == 0 && state->error == 0)
			ft_process_cmd_fork(state);
	}
}
