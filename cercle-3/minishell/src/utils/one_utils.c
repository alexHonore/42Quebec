/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:48:53 by jvillefr          #+#    #+#             */
/*   Updated: 2023/10/09 11:32:08 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	ft_check_other_pi_more(t_state *state, t_node *temp, int i, int j)
{
	while (temp)
	{
		i++;
		if (ft_strncmp(temp->content, "||\0", 3) == 0
			|| (ft_strncmp(temp->content, "||\0", 2) == 0
				&& ft_strncmp(temp->content, "|\0", 2) == 0))
		{
			ft_minishell_err(state, M_TOKENS_ERR, N_TOKENS_ERR);
			g_status = 258;
			return ;
		}
		if (ft_strncmp(temp->content, "|\0", 2) == 0 && j == i)
		{
			ft_minishell_err(state, M_TOKEN_ERR, N_TOKEN_ERR);
			g_status = 258;
			return ;
		}
		temp = temp->next;
	}
}
