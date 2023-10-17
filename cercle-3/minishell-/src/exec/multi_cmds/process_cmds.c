/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:35:48 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 16:51:54 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_status;

void	ft_run_execve(t_state *state)
{
	int	error;

	error = ft_execve(state);
	ft_minishell_err(state, M_PIPE_EXECVE_ERR, N_PIPE_EXECVE_ERR);
	ft_close_fd();
	g_status = error;
	exit(error);
}

void	ft_run_one_child(t_state *state, int *fd)
{
	if (state->index < state->nb_cmds - 1)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
	}
	ft_on_redirection(state);
	if (ft_run_builtin(state) == 0 && state->error == 0)
	{
		ft_run_execve(state);
	}
	ft_close_fd();
	exit(g_status);
}

void	ft_run_childs(t_state *state)
{
	int	fd[2];

	state->index = 0;
	while (state->index < state->nb_cmds && state->error == 0)
	{
		pipe(fd);
		state->pid[state->index] = fork();
		if (state->pid[state->index] == 0)
		{
			ft_run_one_child(state, fd);
		}
		else if (state->index < state->nb_cmds)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
		}
		state->index++;
	}
}

void	ft_wait_childs(t_state *state)
{
	state->index = 0;
	while (state->index < state->nb_cmds)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(state->pid[state->index], &g_status, 0);
		state->index++;
	}
}

void	ft_process_commands(t_state *state)
{
	state->index = 0;
	state->pid = ft_calloc(sizeof(pid_t), state->nb_cmds);
	if (!state->pid)
	{
		ft_minishell_err(state, M_PIPE_ERR, N_PIPE_ERR);
	}
	ft_run_childs(state);
	ft_wait_childs(state);
	ft_free(state->pid);
}
