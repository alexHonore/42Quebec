# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 11:41:50 by anshimiy          #+#    #+#              #
#    Updated: 2022/04/14 12:13:04 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = cd libft && make
LIBFT_A = libft/libft.a

SRCS = ft_printf.c \
		char_functions.c \
		nbr_functions.c \
		hexa_functions.c \
		libft/ft_itoa.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make
	$(AR) $(NAME) $(OBJS)

libft:
	$(GCC) $(CFLAGS) $(LIBFT_A) -o $(NAME)

libfta:
	$(LIBFT)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re