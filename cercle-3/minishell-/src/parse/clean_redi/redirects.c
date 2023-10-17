/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:59:00 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 08:39:54 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// <
void	ft_less_than(t_state *state)
{
	int		index;
	t_cmd	*cmd;
	int		pos;

	index = state->index;
	cmd = &state->cmds[index];
	pos = cmd->i_redi;
	if (cmd->t_redirection[pos] && access(cmd->t_redirection[pos], F_OK) == -1)
	{
		ft_minishell_err(state, M_NO_FILE_DIR_ERR, N_NO_FILE_DIR_ERR);
		state->error++;
		g_status = 256;
		return ;
	}
	cmd->fd_file = open(cmd->t_redirection[pos], O_RDONLY, 0644);
	if (!cmd->fd_file)
	{
		return ;
	}
	dup2(cmd->fd_file, STDIN_FILENO);
}

// >
void	ft_greater_than(t_state *state, int is_dup2)
{
	int		index;
	t_cmd	*cmd;

	index = state->index;
	cmd = &state->cmds[index];
	cmd->fd_file = open(cmd->t_redirection[cmd->i_redi],
			O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (is_dup2 == 1)
		dup2(cmd->fd_file, STDOUT_FILENO);
	else
		close(cmd->fd_file);
}

// <<
void	ft_two_less_than(t_state *state)
{
	t_cmd	*cmd;
	char	*file;
	char	*tmp_file_id;
	char	*cmd_id;
	char	*i_redi;

	cmd = &state->cmds[state->index];
	cmd_id = ft_itoa(cmd->id);
	i_redi = ft_itoa(cmd->i_redi);
	tmp_file_id = ft_strjoin(cmd_id, i_redi);
	file = ft_strjoin(".tmp_heredoc", tmp_file_id);
	ft_free(cmd_id);
	ft_free(i_redi);
	ft_free(tmp_file_id);
	cmd->fd_file = open(file, O_RDONLY, 0644);
	if (cmd->fd_file < 0)
		ft_minishell_err(state, M_NO_FILE_DIR_ERR, N_NO_FILE_DIR_ERR);
	ft_free(file);
	dup2(cmd->fd_file, STDIN_FILENO);
}

// >>
void	ft_two_greater_than(t_state *state, int is_dup2)
{
	int		index;
	t_cmd	*cmd;

	index = state->index;
	cmd = &state->cmds[index];
	cmd->fd_file = open(cmd->t_redirection[cmd->i_redi],
			O_CREAT | O_APPEND | O_RDWR,
			0644);
	if (cmd->fd_file < 0)
	{
		err_mini(state, cmd->t_redirection[cmd->i_redi],
			M_TOKENS_ERR_F, N_TOKENS_ERR_F);
		g_status = 256;
		printf("\n g_sst %d\n", g_status);
		return ;
	}
	if (is_dup2 == 1)
		dup2(cmd->fd_file, STDOUT_FILENO);
	else
		close(cmd->fd_file);
}

int	ft_on_redirection(t_state *state)
{
	int		type;
	int		index;
	t_cmd	*cmd;

	index = state->index;
	cmd = &state->cmds[index];
	cmd->i_redi = 0;
	while (cmd->i_redi < cmd->n_of_redi)
	{
		type = cmd->redirect[cmd->i_redi];
		if (type <= -1 || cmd->i_redi == cmd->n_of_redi - 1)
			return (0);
		else if (type == 0)
			ft_less_than(state);
		else if (type == 1)
			ft_greater_than(state, 1);
		else if (type == 2)
			ft_two_less_than(state);
		else if (type == 3)
			ft_two_greater_than(state, 1);
		cmd->i_redi++;
	}
	return (1);
}
