/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:15:39 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 11:03:48 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_check_other_pipes(t_state *state)
{
	t_node	*temp;
	int		j;
	int		i;

	i = 0;
	temp = ft_get_first_node(state->tokens);
	temp = temp->next;
	j = ft_str_len_node(state->tokens);
	ft_check_other_pi_more(state, temp, i, j);
}

int	ft_is_redi(t_state *state, t_node *temp)
{
	int	j;

	j = 3;
	while (j >= 0)
	{
		if (ft_strncmp(temp->content, state->t_redirection[j],
				ft_strlen(state->t_redirection[j])) == 0)
		{
			return (1);
		}
		j--;
	}
	return (0);
}

int	ft_is_pipe(char *str)
{
	if (ft_strncmp(str, "|\0", 2) == 0 || ft_strncmp(str, "||\0", 2) == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_unexptd_token_check(t_node *list)
{
	t_node	*temp;
	char	c;

	temp = ft_get_first_node(list);
	while (temp)
	{
		if (*temp->content == '<' || *temp->content == '>'
			|| *temp->content == '|' )
		{
			c = *temp->content;
			if (!temp->next)
				return (0);
			temp = temp->next;
			if (*temp->content == c)
			{
				printf("minishell: syntax error near expected token '||'\n");
				g_status = 258;
				return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}

void	ft_check_pipes(t_state *state)
{
	t_node	*temp;

	temp = ft_get_first_node(state->tokens);
	if (temp->content && ft_strncmp(temp->content, "|\0", 2) == 0)
	{
		ft_minishell_err(state, M_TOKEN_ERR, N_TOKEN_ERR);
		g_status = 258;
		return ;
	}
	else if (temp->content && ft_strncmp(temp->content, "||\0", 3) == 0)
	{
		ft_minishell_err(state, M_TOKENS_ERR, N_TOKENS_ERR);
		g_status = 258;
		return ;
	}
	ft_check_other_pipes(state);
}
