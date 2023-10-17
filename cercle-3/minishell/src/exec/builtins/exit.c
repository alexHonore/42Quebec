/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:15 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 08:10:45 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_status;

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_command_exit_more(t_state *state, char *run_command)
{
	if (ft_isdigit_str(run_command) == 0)
	{
		err_mini_exit(state, run_command, "numeric argument required\n",
			255);
		state->stop = STOP;
	}
	else if (ft_arr_size(&run_command) > 2)
	{
		err_mini_exit(state, NULL, "too many arguments\n", 1);
		g_status = 256;
	}
	else
	{
		state->stop = STOP;
	}
}

void	ft_command_exit(t_state *state, char **run_command)
{
	if (state->nb_cmds == 1)
		ft_putstr_fd("exit\n", 2);
	if (ft_arr_size(run_command) == 2)
	{
		if ((run_command[1][0] == '-' && ft_isdigit_str(run_command[1]
				+ 1) == 1) || ft_isdigit_str(run_command[1]) == 1)
		{
			state->error = ft_atoi(run_command[1]);
			g_status = state->error;
		}
		else
		{
			err_mini_exit(state, run_command[1], "numeric argument required\n",
				255);
			g_status = 255;
		}
		state->stop = STOP;
	}
	else
	{
		ft_command_exit_more(state, run_command[1]);
	}
}
