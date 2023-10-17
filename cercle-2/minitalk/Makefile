# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:29:49 by anshimiy          #+#    #+#              #
#    Updated: 2022/09/29 21:08:06 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

SRCS =  server.c \
		client.c \

SRCS_BONUS = 	client_bonus.c \
				server_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

$(NAME):	$(OBJS)
	make -C ./my_lib
	$(CC) $(CFLAGS)  $@.o -o $@ ./my_lib/mylib.a

all: $(NAME)

bonus : $(OBJS_BONUS)
		make -C ./my_lib
		$(CC) $(CFLAGS) $(OBJS) server_bonus.c ./my_lib/mylib.a -o server
		$(CC) $(CFLAGS) $(OBJS) client_bonus.c ./my_lib/mylib.a -o client

clean: 
	$(MAKE) -C ./my_lib clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
