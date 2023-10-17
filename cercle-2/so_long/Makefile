# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 12:59:48 by anshimiy          #+#    #+#              #
#    Updated: 2022/09/28 15:06:21 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS =	ft_printf/ft_printf.c			\
		ft_printf/char_functions.c		\
		ft_printf/hexa_functions.c		\
		ft_printf/nbr_functions.c		\
		ft_printf/ft_itoa.c				\
		ft_split.c				\
		get_next_line_utils.c	\
		get_next_line.c			\
		so_long_free_error.c	\
		so_long_map.c			\
		so_long_map2.c			\
		so_long_move.c			\
		so_long_render.c		\
		so_long_util.c			\
		so_long_util2.c			\
		so_long_util3.c			\
		so_long.c				\

#LIBFTPRINTF = lib/ft_printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
