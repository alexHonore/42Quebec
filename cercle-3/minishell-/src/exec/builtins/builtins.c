/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:15:25 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/09 16:59:51 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_run_builtin(t_state *state)
{
	char	**run_command;
	char	*command;

	run_command = state->cmds[state->index].cmd_args;
	command = run_command[0];
	if (!command)
		return (1);
	if (ft_strncmp(command, "exit\0", 5) == 0)
		ft_command_exit(state, run_command);
	else if (ft_strncmp(command, "env\0", 4) == 0)
		ft_print_table(state->g_env, 1);
	else if (ft_strncmp(command, "unset\0", 6) == 0)
		ft_delete_env(state, run_command);
	else if (ft_strncmp(command, "export\0", 7) == 0)
		ft_add_env(state, run_command, 1);
	else if (ft_strncmp(command, "echo\0", 5) == 0)
		ft_echo(state);
	else if (ft_strncmp(command, "pwd\0", 4) == 0)
		ft_pwd(state);
	else if (ft_strncmp(command, "cd\0", 3) == 0)
		ft_cd(state);
	else
		return (0);
	return (1);
}
