/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:18:13 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 16:21:38 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_create_array(t_state *state, t_cmd *cmd)
{
	t_node	*aff;
	int		i;

	i = 0;
	aff = ft_get_first_node(state->tokens);
	cmd->n_of_redi = ft_number_of_redirection(state, aff, cmd->id) + 1;
	cmd->redirect = ft_calloc(sizeof(int), cmd->n_of_redi);
	cmd->i_redi = 0;
	while (i < cmd->n_of_redi)
	{
		cmd->redirect[i] = -2;
		i++;
	}
	cmd->redirect[0] = -1;
}

int	ft_save_type_redirection(t_state *state, int i)
{
	t_node	*aff;
	int		pipe;

	aff = ft_get_first_node(state->tokens);
	pipe = 0;
	while (aff)
	{
		if (aff->content)
		{
			if (pipe == i)
				ft_save_type_redirection_while(state, aff, i);
			if (ft_strncmp(aff->content, "|\0", 2) == 0)
				pipe++;
		}
		aff = aff->next;
	}
	return (0);
}

char	**ft_content_tokens(t_state *state, int number_pipe, t_node *list)
{
	t_node	*aff;
	char	**table;
	int		i;
	int		pipe;

	i = 0;
	pipe = 0;
	aff = ft_get_first_node(list);
	if (state->nb_cmds == 1)
	{
		while (aff)
		{
			i++;
			aff = aff->next;
		}
	}
	else
		i = ft_content_tokens_i(aff, number_pipe, pipe);
	table = ft_calloc(sizeof(char *), i + 1);
	aff = ft_get_first_node(list);
	ft_content_tokens_table(state, aff, table, number_pipe);
	return (table);
}

void	ft_cmd_args_in_redirection(t_state *state, int i)
{
	t_cmd	*cmd;
	char	**new;
	char	**tmp;
	int		size_copy;

	cmd = &state->cmds[i];
	state->cmds[i].t_redirection = ft_calloc(sizeof(char *), cmd->n_of_redi
			+ 1);
	cmd->i_redi = 0;
	size_copy = -1;
	while (cmd->i_redi < cmd->n_of_redi - 1)
	{
		ft_cmd_args_in_red_divi(state, i, &size_copy);
		cmd->i_redi++;
	}
	tmp = ft_content_tokens(state, i, state->tokens);
	size_copy = ft_arr_size(tmp);
	cmd->i_redi = 0;
	new = ft_cmd_args_in_redirection_create(state, tmp, cmd, size_copy);
	ft_free_str_table(tmp);
	state->cmds[i].cmd_args = NULL;
	state->cmds[i].cmd_args = new;
}

void	ft_create_cmds_array(t_state *state)
{
	int	i;

	i = 0;
	ft_create_t_redirection(state);
	state->cmds = ft_calloc(sizeof(t_cmd), state->nb_cmds);
	while (i < state->nb_cmds)
	{
		state->cmds[i].id = i;
		state->cmds[i].fd_file = -1;
		ft_create_array(state, &state->cmds[i]);
		ft_save_type_redirection(state, i);
		if (state->cmds[i].redirect[0] >= 0)
		{
			ft_cmd_args_in_redirection(state, i);
		}
		else
		{
			state->cmds[i].t_redirection = ft_calloc(sizeof(char *), 1);
			state->cmds[i].cmd_args = ft_content_tokens(state, i,
					state->tokens);
		}
		i++;
	}
}
/*




void ft_view_tcmd(t_cmd *cmd)
{

	    printf("id: %d\n", cmd->id);
    printf("cmd_args: ");
    for (int i = 0; cmd->cmd_args[i] != NULL; i++) {
        printf("%s ", cmd->cmd_args[i]);
    }
    printf("\n");
    printf("cmd: %s\n", cmd->cmd);
    printf("redirect: %d\n", cmd->redirect[1]);
    printf("n_of_redi: %d\n", cmd->n_of_redi);
    printf("i_redi: %d\n", cmd->i_redi);
    printf("t_redirection: ");
    for (int i = 0; cmd->t_redirection[i] != NULL; i++) {
        printf("%s ", cmd->t_redirection[i]);
    }
    printf("\n");
    printf("fd_file: %d\n", cmd->fd_file);
}
void ft_view_state(t_state *state)
{

	printf(ANSI_COLOR_YELLOW"\nVIEW STATE\n" ANSI_COLOR_RESET);
    printf("nb_cmds: %d\n", state->nb_cmds);
	printf("error: %d\n", state->error);

	int i = 0;
	printf(ANSI_COLOR_YELLOW "\n**VIEW 	TOKENS FROM STATE**\n" ANSI_COLOR_RESET);

	ft_view_node(&state->tokens[i]);

	i = 0;
	printf(ANSI_COLOR_YELLOW "\nVIEW CMDS FROM STATE\n"ANSI_COLOR_RESET);
	while (i < state->nb_cmds)
	{
		ft_view_tcmd(&state->cmds[i]);
		printf("\n**************\n");
		i++;
	}


    printf("save_stdout: %d\n", state->save_stdout);
    printf("save_stdin: %d\n", state->save_stdin);
    printf("index: %d\n", state->index);
    printf("error: %d\n", state->error);
    printf("stop: %d\n", state->stop);

}

void ft_view_node(t_node *list)
{
	t_node *token;

	token = ft_get_first_node(list);
        while(token)
          {
             printf("content: %s\n",token->content);
			 printf("i: %d\n", token->i);
			 printf("type: %d\n", token->type);
			 printf("--------------\n");
             token = token->next;
          }
}

*/
