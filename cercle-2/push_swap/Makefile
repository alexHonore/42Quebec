# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:29:49 by anshimiy          #+#    #+#              #
#    Updated: 2022/09/26 16:04:48 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  src/main.c \
		src/push.c \
		src/radix.c \
		src/reverse_rotate.c \
		src/rotate.c \
		src/simple.c \
		src/swap.c \
		utils/check_args.c \
		utils/free_print_list_get_min.c \
		utils/ft_atol.c \
		utils/index.c \
		utils/t_list.c \
		utils/utils.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./my_lib
	@${CC} ${CFLAGS} ${OBJS} ./my_lib/mylib.a -o ${NAME}

clean: 
	@${MAKE} -C ./my_lib fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
