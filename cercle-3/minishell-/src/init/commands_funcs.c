/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:21:32 by anshimiy          #+#    #+#             */
/*   Updated: 2023/08/31 14:19:25 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_number_of_redirection(t_state *state, t_node *aff, int number_pipe)
{
	int	number;
	int	pipe;

	number = 0;
	pipe = 0;
	while (aff)
	{
		if (aff->content)
		{
			if (pipe == number_pipe && ft_is_redi(state, aff) == 1)
				number++;
			else if (ft_strncmp(aff->content, "|\0", 2) == 0)
				pipe++;
		}
		aff = aff->next;
	}
	return (number);
}

int	ft_save_type_redirection_while(t_state *state, t_node *aff, int i)
{
	int		j;
	t_cmd	*cmd;

	j = 3;
	cmd = &state->cmds[i];
	while (j >= 0)
	{
		if (ft_strncmp(aff->content, state->t_redirection[j],
				ft_strlen(state->t_redirection[j])) == 0)
		{
			state->cmds[i].redirect[cmd->i_redi] = j;
			cmd->i_redi++;
			return (1);
		}
		j--;
	}
	return (0);
}

char	**ft_cmd_args_in_redirection_create(t_state *state, char **tmp,
		t_cmd *cmd, int size_copy)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(sizeof(char *), size_copy);
	while (i < size_copy)
	{
		if (cmd->i_redi < cmd->n_of_redi - 1 && ft_check_t_redi(state, cmd, tmp,
				i) == 1)
		{
			cmd->i_redi++;
			i++;
		}
		else if (i < size_copy)
		{
			new[j] = ft_strdup(tmp[i]);
			j++;
		}
		i++;
	}
	return (new);
}

char	*ft_get_char_node(t_node *list, int position)
{
	int		i;
	t_node	*aff;

	i = 0;
	aff = ft_get_first_node(list);
	while (aff)
	{
		if (position == i)
		{
			return (aff->content);
		}
		i++;
		aff = aff->next;
	}
	return (NULL);
}

void	ft_cmd_args_in_red_divi(t_state *state, int i, int *start)
{
	int		position_redi;
	t_cmd	*cmd;

	cmd = &state->cmds[i];
	position_redi = ft_position_in_token(state->tokens,
			state->t_redirection[cmd->redirect[cmd->i_redi]],
			i, start);
	*start = position_redi;
	if (position_redi >= ft_tokens_size(state->tokens) - 2)
	{
		state->cmds[i].cmd_args = NULL;
		ft_minishell_err(state, M_UNXPTD_TOKEN_ERR, N_UNXPTD_TOKEN_ERR);
		state->error++;
		return ;
	}
	position_redi++;
	cmd->t_redirection[cmd->i_redi] = ft_strdup(ft_get_char_node(state->tokens,
				position_redi));
}
