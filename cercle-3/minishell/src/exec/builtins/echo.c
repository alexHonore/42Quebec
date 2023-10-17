/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:23:25 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 15:29:52 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_echo(t_state *state)
{
	char	**past;
	int		size;

	past = state->cmds[state->index].cmd_args;
	size = ft_arr_size(past);
	if (size == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	else if (size >= 2 && ft_strncmp(past[1], "-n",
			2) == 0 && ft_is_only_char(past[1] + 2, 'n') == 1)
	{
		ft_print_table(past + 2, 0);
		return ;
	}
	else if (size >= 2)
	{
		ft_print_table(past + 1, 2);
		return ;
	}
}
