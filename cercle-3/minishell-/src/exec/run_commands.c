/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:45:30 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/11 15:25:07 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_stop_pipe(t_state *state)
{
	int		i;
	t_node	*aff;

	i = 0;
	aff = ft_get_first_node(state->tokens);
	while (aff)
	{
		if (aff->content)
		{
			if (ft_strncmp(aff->content, "||\0", 3) == 0)
				return (i);
			i++;
		}
		aff = aff->next;
	}
	return (-1);
}

void	ft_run_commands(t_state *state)
{
	int	n_cmd_bfr_pipes;

	signal(SIGQUIT, ft_sigint_handler_more);
	state->save_stdout = dup(STDOUT_FILENO);
	state->save_stdin = dup(STDIN_FILENO);
	n_cmd_bfr_pipes = ft_stop_pipe(state);
	if (n_cmd_bfr_pipes > -1)
		state->nb_cmds = n_cmd_bfr_pipes;
	if (state->nb_cmds == 1)
		ft_process_command(state);
	else
		ft_process_commands(state);
	dup2(state->save_stdout, STDOUT_FILENO);
	dup2(state->save_stdin, STDIN_FILENO);
	close(state->save_stdin);
	close(state->save_stdout);
}
