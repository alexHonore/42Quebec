/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:25:15 by anshimiy          #+#    #+#             */
/*   Updated: 2023/09/19 10:17:41 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_delete_process(t_cmd *cmd)
{
	char	*number;
	char	*i_redi;
	char	*file;
	char	*file_tem;

	number = ft_itoa(cmd->id);
	i_redi = ft_itoa(cmd->i_redi);
	file_tem = ft_strjoin(number, i_redi);
	file = ft_strjoin(".tmp_heredoc", file_tem);
	unlink(file);
	ft_free(number);
	ft_free(i_redi);
	ft_free(file_tem);
	ft_free(file);
}

void	ft_delete_herodoc(t_cmd *cmd)
{
	cmd->i_redi = 0;
	while (cmd->i_redi < cmd->n_of_redi - 1)
	{
		ft_delete_process(cmd);
		cmd->i_redi++;
	}
}

void	ft_free_commands_table(char **table)
{
	int	j;

	j = 0;
	while (table && table[j])
	{
		ft_free(table[j]);
		j++;
	}
	ft_free(table);
}

void	ft_free_commands(t_state *state)
{
	int	i;

	i = 0;
	i = 0;
	if (!state->cmds)
	{
		return ;
	}
	while (i < state->nb_cmds && state->error == 0)
	{
		ft_free_commands_table(state->cmds[i].cmd_args);
		ft_delete_herodoc(&state->cmds[i]);
		ft_free(state->cmds[i].cmd);
		ft_free(state->cmds[i].redirect);
		ft_free_commands_table(state->cmds[i].t_redirection);
		if (state->cmds[i].fd_file > 0)
		{
			close(state->cmds[i].fd_file);
		}
		i++;
	}
	state->cmds = ft_free(state->cmds);
}

void	ft_free_all(t_state *state)
{
	ft_free_commands(state);
	state->t_redirection = (char **)ft_free_str_table(state->t_redirection);
}
