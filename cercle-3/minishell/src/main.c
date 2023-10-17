/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:50:40 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 12:37:34 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_status;

/// @brief 	Increments SHLVL each time a state is initialized
/// @param state
void	ft_shlvl_increment(t_state *state)
{
	char	**past;
	char	*str_num;
	int		num;

	if (ft_find_env_value(state->g_env, "SHLVL=") != NULL
		&& ft_strlen(ft_find_env_value(state->g_env, "SHLVL=")) > 0)
	{
		num = ft_atoi(ft_find_env_value(state->g_env, "SHLVL="));
		num++;
		str_num = ft_itoa(num);
		past = ft_calloc(sizeof(char *), 3);
		past[0] = ft_strdup("1");
		past[1] = ft_strjoin("SHLVL=", str_num);
		ft_add_env(state, past, 1);
		ft_free_str_table(past);
		ft_free(str_num);
	}
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_status = 1;
}

/*
 * @brief	Where all variables are initialized, parsed and treated
 * @note	ft_check_pipes(state);          Checks if pipe use is legit...
			ft_create_cmds_array(state); 	Init state->cmds...
			ft_add_info_commands(state); 	Handle redirection/heredocs...
			ft_run_commands(state);      	Run...
			ft_update_g_status(); 			Update error code
			ft_check_exit(state);        	Clean used memory & fds of last cmd
 * @param 	*line:
 * @param 	*state:
 * @param 	*tokens:
 * @retval	None
*/
void	ft_run_code(char *line, t_state *state, t_node *tokens)
{
	state->error = 0;
	skip_tab(line);
	tokens = ft_get_tokens(line, state);
	state->nb_cmds = ft_get_nb_cmds_pipe(tokens);
	if (ft_unexptd_token_check(tokens) == 0
		&& state->nb_cmds > 0 && state->error == 0)
	{
		state->tokens = tokens;
		ft_check_pipes(state);
		ft_create_cmds_array(state);
		ft_add_info_commands(state);
		ft_run_commands(state);
		ft_update_g_status();
		ft_check_exit(state);
	}
	ft_lst_free(tokens);
}

void	ft_init_state(t_state *state, char **envp)
{
	state->g_env = ft_get_env(envp, 1, -1);
	state->t_redirection = NULL;
	state->cmds = NULL;
	state->pid = NULL;
	state->nb_cmds = 0;
	state->index = 0;
	state->stop = NO_ERROR;
	state->save_stdout = 0;
	state->save_stdin = 0;
	state->error = NO_ERROR;
	ft_shlvl_increment(state);
}

int	main(int argc, char **argv, char **envp)
{
	t_state	state;
	t_node	tokens;
	char	*line;

	line = NULL;
	(void)argc;
	(void)argv;
	ft_init_state(&state, envp);
	while (state.stop != STOP)
	{
		signal(SIGINT, ft_sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell$ ");
		if (line && *line && ft_is_space(line) == 0)
		{
			add_history(line);
			ft_run_code(line, &state, &tokens);
		}
		if (!line)
			break ;
		ft_free(line);
	}
	done(&state);
	return (0);
}
