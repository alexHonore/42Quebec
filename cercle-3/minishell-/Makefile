# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 20:37:11 by anshimiy          #+#    #+#              #
#    Updated: 2023/10/09 12:26:15 by jvillefr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS
PROJECT	:=	minishell
CC		:=	gcc -g -Wall -Werror -Wextra  #-lreadline, gdb debug enabled
RM		:=	rm -f
READLINE = ./includes/readline/libreadline.a ./includes/readline/libhistory.a -lreadline -lcurses
MY_LIB	:=	./includes/my_lib

# PATHS

SRC	:=	src/

EXEC		:=	$(SRC)exec/
_BUILTIN	:=	$(EXEC)builtins/
_MULTI_CMD	:=	$(EXEC)multi_cmds/
_SINGLE_CMD	:=	$(EXEC)single_cmd/
EXIT		:=	$(SRC)exit/
INIT		:=	$(SRC)init/
PARSE		:=	$(SRC)parse/
_CLEAN_REDI :=	$(PARSE)clean_redi/
UTILS		:=	$(SRC)utils/

# FILES
SRC	:=	$(SRC)main.c 																										\
		$(EXEC)execve.c	$(EXEC)run_commands.c																				\
		$(_BUILTIN)builtins.c $(_BUILTIN)cd.c $(_BUILTIN)echo.c $(_BUILTIN)env.c											\
		$(_BUILTIN)unset.c $(_BUILTIN)exit.c $(_BUILTIN)export.c															\
		$(_MULTI_CMD)process_cmds.c																							\
		$(_SINGLE_CMD)process_cmd.c																							\
		$(PARSE)split.c $(PARSE)checking.c 																					\
		$(_CLEAN_REDI)add_commands_funcs.c $(_CLEAN_REDI)add_commands.c $(_CLEAN_REDI)heredoc.c $(_CLEAN_REDI)redirects.c	\
		$(INIT)init.c $(INIT)get.c $(INIT)commands.c $(INIT)commands_funcs.c												\
		$(UTILS)commands_utils.c $(UTILS)node.c $(UTILS)mini_utils.c $(UTILS)echo_utils.c $(UTILS)echo_more_utils.c																	\
		$(UTILS)position.c $(UTILS)print_table.c $(UTILS)add_commands_utils.c $(UTILS)one_utils.c												\
		$(UTILS)tables_utils.c $(UTILS)str_utils.c $(UTILS)only_str_isalnum.c $(UTILS)clean_space_str.c 					\
		$(EXIT)close.c $(EXIT)error.c $(EXIT)free.c	$(EXIT)free_ms.c	 													\

# COLORS
RED		:=	\033[0;31m
GREEN	:=	\033[0;32m
YELLOW	:=	\033[0;33m
BLUE	:=	\033[0;34m
PURPLE	:=	\033[0;35m
CYAN	:=	\033[0;36m
WHITE	:=	\033[0;37m
RESET	:=	\033[0m


# RULES
all: $(PROJECT)

$(PROJECT): $(SRC)
	@cd ./includes/readline && ./configure
	@make everything -C ./includes/readline
	@make -C $(MY_LIB)
	@$(CC) -o $(PROJECT) $(SRC) $(READLINE) $(MY_LIB)/mylib.a
	@echo "$(GREEN)$(PROJECT) created$(RESET)"

clean:
#	@echo "$(RED)$(PROJECT) deleted$(RESET)"
	@make -C $(MY_LIB) clean
#	@$(RM) $(PROJECT)

fclean: clean
	@echo "$(RED)$(PROJECT) deleted$(RESET)"
	@make -C $(MY_LIB) fclean
	@$(RM) $(PROJECT)

re: fclean all

norm:
	@norminette $(SRC) ./includes/minishell.h ./includes/my_lib/
check_leak:
	@valgrind --show-leak-kinds=all --track-origins=yes --trace-children=yes --leak-check=full --track-fds=yes --suppressions=supp.txt ./minishell

.PHONY: all clean fclean re norm
