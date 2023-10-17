/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:29:29 by anshimiy          #+#    #+#             */
/*   Updated: 2022/09/23 18:42:47 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
*/
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		collected;
	int		cnt;
	int		collect_cnt;
	char	**two_d_map;
	char	**flood_fill_map;
	void	*tile;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	int		time;
	int		collectibles_count;
	int		exits_count;
	int		player_count;
	int		reachable_exits_count;
	int		reachable_collectibles_count;
}			t_game;

// wanted to make a 2nd verification for c/e/p for testings,
// it ends up I did'nt want to modify everything so there's 2 way to check it ik
typedef struct s_check
{
	int		collect;
	int		exit;
	int		player;
	size_t	len;
}			t_check;

typedef struct s_args
{
	int		c;
	int		width;
	int		has_width;
	int		precision;
	int		has_precision;
}			t_args;

int			ft_printf(const char *format, ...);

void		initialize_args(t_args *args);
char		*read_args(t_args *args, char *itr);
char		*ft_strchrr(char *str, char c);
int			ft_put_conv(t_args *args, va_list ap);
int			ft_strlenn(char *s);

int			ft_printf(const char *format, ...);
int			ft_printchar(char c, int fd);
int			ft_print_u_nbr(unsigned int n);
int			ft_address2(unsigned long long num);
int			ft_hex_len(unsigned long num);
void		ft_pointer(unsigned long num);
int			ft_puthexadecimal(unsigned int n, const char c);
int			ft_printnbr(int n);
int			ft_printstr(char *s, int fd);
char		*ft_itoa(int n);

char		*get_next_line(int fd);

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

char		**ft_split(char const *s, char c);

void		ft_error(int exit_code);
void		game_init(t_game *game);
void		move_w(t_game *game);
void		move_s(t_game *game);
void		move_a(t_game *game);
void		move_d(t_game *game);
void		check_init(t_check *check);
int			ft_render(t_game *game, char *map);
int			move_check(t_game *game, int y, int x);
int			key_press(int keycode, t_game *game);
int			is_invalid_char(char c);
int			is_invalid_line(char *line);
int			check_close(char *line, size_t len);
int			is_not_rectangular(char *line, size_t len);
int			line_not_full_walls(char *line, size_t len);
int			last_line_not_full_walls(char *line, size_t len);
int			cnt_collect(char *map);
int			exit_game(t_game *game);
char		*check_cep(t_game *game, char *map);
char		*ft_str_free(char *line, char *map);
size_t		ft_strlen_newline(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

char		*check_map(int fd, t_game *game);
int			throw_error(char *error);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**generate_map(t_game *game, char *path);
void		count_map_elements(t_game *game);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			has_valid_path(t_game *game, int x, int y);
void		free_game(t_game *game);

char		*ft_strndup(const char *s1, size_t n);
char		*read_map(int fd);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
int			mlx_destroy_exit(t_game *game);
#endif
