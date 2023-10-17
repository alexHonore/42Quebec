/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:24:12 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 15:45:25 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_execve_direction(t_state *state, int i)
{
	int	error;

	ft_close_fd();
	error = execve(state->cmds[i].cmd_args[0], state->cmds[i].cmd_args,
			state->g_env);
	return (error);
}

void	ft_execve_no_path(t_state *state)
{
	char	**erro_path;

	erro_path = ft_calloc(sizeof(char *), 2);
	erro_path[0] = ft_strdup("PATH");
	ft_minishell_err(state, M_ENV_PATH_ERR, N_ENV_PATH_ERR);
	ft_free_str_table(erro_path);
	ft_close_fd();
	exit(errno);
}

// Find the path of the command, if it is not found, it returns null.
char	*ft_get_command_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*new_c;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		new_c = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(new_c, 0) == 0)
			return (new_c);
		free(new_c);
		paths++;
	}
	return (NULL);
}

void	ft_execve_get_path(t_state *state, int i)
{
	char	*env_path;
	char	**cmd_paths;

	env_path = ft_find_env_value(state->g_env, "PATH=");
	cmd_paths = ft_split(env_path, ':');
	state->cmds[i].cmd = ft_get_command_path(cmd_paths,
			state->cmds[i].cmd_args[0]);
	cmd_paths = (char **)ft_free_str_table(cmd_paths);
}

int	ft_execve(t_state *state)
{
	int	error;
	int	i;

	i = state->index;
	if (access(state->cmds[i].cmd_args[0], X_OK | F_OK) != -1)
		return (ft_execve_direction(state, i));
	if (ft_find_env_value(state->g_env, "PATH=") == NULL)
		ft_execve_no_path(state);
	ft_execve_get_path(state, i);
	if (!state->cmds[i].cmd)
	{
		err_mini(state, state->cmds[i].cmd_args[0], M_PATH_ERR, N_PATH_ERR);
		ft_close_fd();
		exit(errno);
	}
	ft_close_fd();
	error = execve(state->cmds[i].cmd, state->cmds[i].cmd_args, state->g_env);
	return (error);
}
