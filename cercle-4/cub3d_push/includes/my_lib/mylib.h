/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:36:52 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 16:23:19 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
/* to comment depending of your needs */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_free_str_array(char **array);
void				ft_free(void *ptr);
void				ft_free_two(void *ptr1, void *ptr2);
void				ft_free_three(void *ptr1, void *ptr2, void *ptr3);
void				ft_free_int_array(int **array, int size);
int					ft_get_arr_size(void **arr);
int					ft_char_in_str(char *str, char c);
int					ft_str_made_of_set(char *str, char *set);
int					ft_str_made_one_set(char *str, char *set);
char				*ft_strchr_set(const char *str, const char *set);
void				ft_print_array(char **arr);
void				ft_print_int_array(int **arr, int max_size);
/* to comment depending of your needs */
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// ft_printf.c
int					ft_print_string(va_list vl, char c);
int					ft_printf(const char *str, ...);
// hexa_functions.c
void				ft_hexa(unsigned int nbr, const char c);
int					ft_puthexadecimal(unsigned int n, const char c);
void				ft_pointer(unsigned long num);
int					ft_hex_len(unsigned long num);
int					ft_address2(unsigned long long ptr);
// nbr_functions.c
int					ft_nbr_len(unsigned long num);
int					ft_printnbr(int n);
char				*ft_uitoa(unsigned int n);
int					ft_print_u_nbr(unsigned int n);
// char functions.c
int					ft_printchar(char c, int fd);
int					ft_printstr(char *s, int fd);

int					throw_error(char *error, int exit_code);
int					throw_error_detail(char *error, char *error_msg,
						int exit_code);
long int			ft_atol(const char *str);
int					ft_nb_out_bounds(char **argv);

// gnl
char				*get_next_line(int fd);
char				*get_line(char **line, char **stash);

#endif