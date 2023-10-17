/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:25:03 by anshimiy          #+#    #+#             */
/*   Updated: 2023/05/16 15:01:48 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_t_redi(t_state *state, t_cmd *cmd, char **tmp, int i)
{
	if (ft_strncmp(state->t_redirection[cmd->redirect[cmd->i_redi]],
			tmp[i],
			ft_strlen(tmp[i])) == 0)
		return (1);
	return (0);
}

int	ft_content_tokens_i(t_node *aff, int number_pipe, int pipe)
{
	int	i;

	i = 0;
	while (aff)
	{
		if (aff->content && ft_is_pipe(aff->content) == 1)
			pipe++;
		else if (pipe > number_pipe)
			break ;
		else if (pipe == number_pipe)
			i++;
		aff = aff->next;
	}
	return (i);
}

void	ft_content_tokens_table_else(t_node *aff, int number_pipe, char **table)
{
	int	pipe;
	int	i;

	i = 0;
	pipe = 0;
	while (aff)
	{
		if (aff->content && ft_is_pipe(aff->content) == 1)
			pipe++;
		else if (pipe > number_pipe)
			break ;
		else if (pipe == number_pipe)
		{
			table[i] = ft_strdup(aff->content);
			i++;
		}
		aff = aff->next;
	}
}

void	ft_content_tokens_table(t_state *state, t_node *aff, char **table,
		int number_pipe)
{
	int	i;

	i = 0;
	if (state->nb_cmds == 1)
	{
		while (aff)
		{
			table[i] = ft_strdup(aff->content);
			aff = aff->next;
			i++;
		}
	}
	else
		ft_content_tokens_table_else(aff, number_pipe, table);
}

int	ft_tokens_size(t_node *list)
{
	t_node	*aff;
	int		i;

	i = 1;
	aff = ft_get_first_node(list);
	while (aff)
	{
		i++;
		aff = aff->next;
	}
	return (i);
}
