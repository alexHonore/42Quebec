# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 20:03:26 by anshimiy          #+#    #+#              #
#    Updated: 2022/11/19 17:20:19 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

SRCDIR = src/

SRCS =  src/main.c			\
		src/monitoring.c	\
		src/threads.c		\
		src/init_parse.c	\
		src/utils.c			\

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

# .o files in bin
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: $(NAME)

$(NAME):	$(OBJS)
	$(HIDE) make -C ./includes/my_lib
	$(HIDE) $(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./includes/my_lib/mylib.a
	@echo "$(GREEN)$(NAME) compiled!$(CEND)"

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c| $(OBJDIR)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE) mkdir -p $@

clean: 
	$(HIDE) $(MAKE) -C ./includes/my_lib clean
	$(HIDE) $(RM) $(OBJS)
	@echo "$(YELLOW)$(NAME) cleaned!$(CEND)"
	@echo "$(RED)  _.,-----/=\-----,._"
	@echo " (__ ~~~.......~~~ __)"
	@echo "  | ~~~.........~~~ |"
	@echo "  | |  ; ,   , ;  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  |. \_| |   | |_/ .|"
	@echo "   °-,.__ ~~~ __.,-°$(CEND)"
	
fclean: clean
	$(HIDE) $(MAKE) -C ./includes/my_lib fclean
	$(HIDE) $(RM) $(NAME)

re: fclean all

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[0;36m
CEND = \033[0m
CBOLD     = \033[1m
.PHONY: all clean fclean re 