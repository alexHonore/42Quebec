/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:36:28 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 16:18:24 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./my_lib/mylib.h"
# include "./readline/history.h"
# include "./readline/readline.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>

// Error control,
// N is the number and M is the message
# define STOP 1
# define NO_ERROR 0
# define M_PATH_ERR " command not found\n"
# define N_PATH_ERR 1
# define M_EXECVE_ERR "minishell: execution error\n"
# define N_EXECVE_ERR 2
# define M_ENV_PATH_ERR "minishell: path not found\n"
# define N_ENV_PATH_ERR 3
# define M_PIPE_ERR "minishell: error creating pipe\n"
# define N_PIPE_ERR 4
# define M_PIPE_EXECVE_ERR "minishell: error creating pipe\n"
# define N_PIPE_EXECVE_ERR 5
# define M_UNSET_ARG_ERR "minishell: missing arg in unset\n"
# define N_UNSET_ARG_ERR 6
# define M_NUMBER_ARG_ERR "minishell: numeric argument required\n"
# define N_NUMBER_ARG_ERR 8
# define N_HOME_UNSET_ERR 10
# define M_NO_FILE_DIR_ERR "minishell: no such file or directory\n"
# define N_NO_FILE_DIR_ERR 11
# define M_UNXPTD_TOKEN_ERR "minishell: syntax error near unexpected tokens\n"
# define N_UNXPTD_TOKEN_ERR 12
# define M_EXPORT_ERR "minishell: export: not a valid identifier\n"
# define N_EXPORT_ERR 13
# define M_TOKEN_ERR "minishell: syntax error near unexpected token '|'\n"
# define N_TOKEN_ERR 14
# define M_TOKENS_ERR "minishell: syntax error near unexpected token '||'\n"
# define N_TOKENS_ERR 15
# define M_TOKENS_ERR_F "Permission denied\n"
# define N_TOKENS_ERR_F 16
# define MAX_INPUT_LENGTH 1024 // Juin -- -- --
# define ANSI_COLOR_MAGENTA   "\x1b[36m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_RESET   "\x1b[0m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define SIGTERM 15
// Error control
extern int			g_status;

// array commands
typedef struct s_cmd
{
	int				id;
	char			**cmd_args;
	char			*cmd;
	int				*redirect;
	int				n_of_redi;
	int				i_redi;
	char			**t_redirection;
	int				fd_file;
}					t_cmd;

typedef struct s_node
{
	char			*content;
	int				i;
	int				type;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_states
{
	char			**t_redirection;
	char			**g_env;
	t_node			*tokens;
	t_cmd			*cmds;
	pid_t			*pid;
	int				save_stdout;
	int				save_stdin;
	int				nb_cmds;
	int				index;
	int				error;
	int				stop;
}					t_state;

void				ft_fork_signal(void);
void				ft_lst_add_back(t_node **list, char *content);
void				ft_lst_free(t_node *list);
char				*ft_trim_char(char *str, int ptr);
int					ft_unexptd_token_check(t_node *list);

// -- split
int					ft_is_splitable(char c);
t_node				*ft_get_tokens(char *args, t_state *state);

// -- ft_minishell
void				ft_create_cmds_array(t_state *state);
void				ft_add_info_commands(t_state *state);
void				ft_run_commands(t_state *state);
void				ft_update_g_status(void);
void				ft_check_exit(t_state *state);
void				ft_check_pipes(t_state *state);

// -- ft_run_commands
void				ft_process_command(t_state *state);
void				ft_process_commands(t_state *state);

//  --> ft_create_cmds_array
int					ft_position_in_token(t_node *list, char *str, int n_pipe,
						int *start);
void				ft_create_t_redirection(t_state *state);
char				**ft_cmd_args_in_redirection_create(t_state *state,
						char **tmp,
						t_cmd *cmd,
						int size_copy);
int					ft_save_type_redirection_while(t_state *state, t_node *aff,
						int i);

// -- env
char				**ft_get_env(char **old, int size, int free_old);
char				*ft_find_env_value(char **envp, char *path);

// -- tables
int					ft_arr_size(char **array);

// -- free
void				*ft_free(void *ptr);
void				**ft_free_str_table(char **array);
void				ft_close_fd(void);
void				ft_free_all(t_state *state);

// -- spc cmds
int					ft_run_builtin(t_state *state);
int					ft_execve(t_state *state);
int					ft_delete_env(t_state *state, char **env_name);
int					ft_add_env(t_state *state, char **past, int check);
void				ft_env_export(t_state *state, char *str, int check);

// -- redirection
int					ft_on_redirection(t_state *state);
void				ft_create_herodoc(t_state *state, int index);
void				ft_greater_than(t_state *state, int is_dup2);
void				ft_two_greater_than(t_state *state, int is_dup2);

// str
char				*ft_clean_space_str(char *str);
int					ft_strchr_get_i(const char *s, int c);
void				ft_str_to_str(char *dst, char *src);
char				*ft_only_str_isalnum(char *str);
int					ft_str_in_str(char *str, char *find);

// -- tokens utils
int					ft_tokens_size(t_node *list);

// -- ft_run_builtin
void				ft_command_exit(t_state *state, char **run_command);
void				ft_print_table(char **str, int new_line);
void				ft_echo(t_state *state);
void				ft_pwd(t_state *state);
int					ft_is_only_char(char *str, int c);

t_node				*ft_get_first_node(t_node *list);
t_node				*ft_get_node(t_node *list, int i);
int					ft_strcmp(char *s1, char *s2);
void				ft_minishell_err(t_state *state, char *msg, int err);
int					ft_is_pipe(char *str);
int					ft_check_t_redi(t_state *state, t_cmd *cmd, char **tmp,
						int i);
int					ft_is_redi(t_state *state, t_node *aff);
void				ft_content_tokens_table(t_state *state, t_node *aff,
						char **table, int number_pipe);
int					ft_content_tokens_i(t_node *aff, int number_pipe, int pipe);
void				ft_cmd_args_in_red_divi(t_state *state, int i, int *start);
int					ft_number_of_redirection(t_state *state, t_node *aff,
						int number_pipe);
void				ft_handle_env_varibles(t_state *state, int i, int j);
void				ft_init_tmp_head(t_node **list);
void				ft_delete_head(t_node **list);
int					ft_get_nb_cmds_pipe(t_node *list);
void				ft_cd(t_state *state);
char				*ft_cat_env_value(char **env, char *path, int plus);
char				*ft_free_3_ret(char *to_free_1, char *to_free_2,
						char *to_free_3, char *to_return);

void				ft_view_node(t_node *tokens);
void				t_view_tcmd(t_cmd *cmd);

void				ft_sigint_handler(int signum);
void				ft_heredoc(void);
void				ft_view_state(t_state *state);
void				signal_heredoc(int sig);
void				min_shell_err(t_state *state, char *cmd,
						char *msg, int err);
void				err_mini(t_state *state, char *arg,
						char *msg_error, int err);
void				err_mini_exit(t_state *state, char *arg,
						char *msg_error, int err);
int					ft_str_size(char *str);
void				done(t_state *state);
void				ft_cd_mor(t_state *state);
void				ft_command_exit_more(t_state *state, char *run_command);
void				ft_var_to_val_mor(char *new, char **table, int i);
int					ft_get_tokens_mor(t_state *state, char *args, int i);
int					ft_is_space(char *line);
int					ft_str_len_node(t_node *list);
void				ft_sigint_handler_more(int signum);
void				get_double_sign_away(char *s);
int					more_then_two_dollar(char *str);
void				delete_by_index(char *s, size_t index);
char				*extract_after_index(char *s, size_t index);
char				*extract_before_index(char *s, size_t index);
int					count_double_dollar(char *str);
void				get_double_sign_away(char *str);
void				re_arrange_table_double(t_state *state, char **s, int *num);
char				*re_arrange_table(t_state *state, char *s, int *num);
int					count_dollar(char *str);
char				*ft_modif(char *cmd_args, char **env, int j);
int					ft_is_delete(t_state *state, int *num, char *tmp);
void				ft_check_other_pi_more(t_state *state,
						t_node *temp, int i, int j);
int					ft_delete_env_for_cd(t_state *state, char **env_name);
void				ft_ha_sig(int sig);
void				ft_handle_heredoc(int signum);
char				*ft_var_first_cond(t_state *state, char *s, int *num);
void				skip_tab(char *s);
void				replace_quotes(char *str);
#endif
