# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:39:11 by anshimiy          #+#    #+#              #
#    Updated: 2023/10/15 17:17:51 by anshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

SRCDIR = src/
BONUS_SRCDIR = src_bonus/
PARSE = parse/
UTILS = utils/
RAYCAST = raycasting/

MLXDIR = ./includes/MLX42/
MYLIB_DIR = ./includes/my_lib/

SRCS =  $(SRCDIR)main.c	$(SRCDIR)cub3d.c																								\
		$(SRCDIR)$(UTILS)errors.c $(SRCDIR)$(UTILS)map_position.c $(SRCDIR)$(UTILS)ft_split_set.c $(SRCDIR)$(UTILS)init_draw.c		\
		$(SRCDIR)$(UTILS)draw.c $(SRCDIR)$(UTILS)math.c $(SRCDIR)$(UTILS)mlx.c  		\
		$(SRCDIR)$(PARSE)color.c $(SRCDIR)$(PARSE)init.c $(SRCDIR)$(PARSE)parse.c $(SRCDIR)$(PARSE)texture_parsing.c					\
		$(SRCDIR)$(PARSE)map.c $(SRCDIR)$(PARSE)dimentions.c $(SRCDIR)$(PARSE)flood.c														\
		$(SRCDIR)$(RAYCAST)raycaster.c $(SRCDIR)$(RAYCAST)movements.c $(SRCDIR)$(RAYCAST)init.c $(SRCDIR)$(RAYCAST)walls.c		\

BONUS_SRCS =  $(BONUS_SRCDIR)main_bonus.c	$(BONUS_SRCDIR)cub3d_bonus.c \
		 	  $(BONUS_SRCDIR)$(UTILS)errors_bonus.c $(BONUS_SRCDIR)$(UTILS)map_position_bonus.c $(BONUS_SRCDIR)$(UTILS)ft_split_set_bonus.c $(BONUS_SRCDIR)$(UTILS)init_draw_bonus.c		\
		      $(BONUS_SRCDIR)$(UTILS)draw_bonus.c $(BONUS_SRCDIR)$(UTILS)math_bonus.c $(BONUS_SRCDIR)$(UTILS)mlx_bonus.c $(BONUS_SRCDIR)$(UTILS)minimap_bonus.c 		\
		      $(BONUS_SRCDIR)$(PARSE)color_bonus.c $(BONUS_SRCDIR)$(PARSE)init_bonus.c $(BONUS_SRCDIR)$(PARSE)parse_bonus.c $(BONUS_SRCDIR)$(PARSE)texture_parsing_bonus.c					\
		      $(BONUS_SRCDIR)$(PARSE)map_bonus.c $(BONUS_SRCDIR)$(PARSE)dimentions_bonus.c $(BONUS_SRCDIR)$(PARSE)flood_bonus.c														\
		      $(BONUS_SRCDIR)$(RAYCAST)raycaster_bonus.c $(BONUS_SRCDIR)$(RAYCAST)movements_bonus.c $(BONUS_SRCDIR)$(RAYCAST)init_bonus.c $(BONUS_SRCDIR)$(RAYCAST)walls_bonus.c $(BONUS_SRCDIR)$(RAYCAST)spe_hooks_bonus.c		\

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LINKS	= 
MLXFLAGS = -lglfw -L$(shell brew --prefix glfw)/lib -framework Cocoa -framework OpenGL -framework IOKit
MLXLIB = $(MLXDIR)build/libmlx42.a
MYLIB = ./includes/my_lib/mylib.a
RM = rm -rf

# .o files in bin
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))
BONUS_OBJ	=	$(patsubst $(BONUS_SRCDIR)%.c,$(OBJDIR)%.o,$(BONUS_SRCS))

all: $(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(HIDE) make -C ./includes/my_lib
	$(HIDE) @$(CC) $(MLXLIB) $(MYLIB) $(MLXFLAGS) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME) 
	@echo "$(GREEN)$(NAME) compiled!$(CEND)"

bonus: $(BONUS_OBJ)
	$(HIDE) make -C ./includes/my_lib
	$(HIDE) @$(CC) $(MLXLIB) $(MYLIB) $(MLXFLAGS) $(CFLAGS) $(BONUS_OBJ) $(LINKS) -o $(NAME)
	@echo "$(GREEN)$(NAME) bonus cub compiled!$(CEND)"

$(MLXLIB):
	@echo "$(CYAN)Compiling MLX42 library...$(CEND)"
	@cmake -S $(MLXDIR) -B $(MLXDIR)build
	$(HIDE) @make -C $(MLXDIR)build
	@echo "$(GREEN)MLX42 compiled.$(CEND)"

$(MYLIB):
	@echo "$(CYAN)Compiling my_lib...$(CEND)"
	$(HIDE) make -C ./includes/my_lib
	@echo "$(GREEN)My_lib compiled.$(CEND)"


# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c| $(OBJDIR)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

# Compiles sources into objects bonus
$(BONUS_OBJ): $(OBJDIR)%.o : $(BONUS_SRCDIR)%.c| $(OBJDIR)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE) mkdir -p $@ $(OBJDIR)$(PARSE) $(OBJDIR)$(UTILS) $(OBJDIR)$(RAYCAST)

clean: 
	$(HIDE) $(MAKE) -C ./includes/my_lib clean
	$(HIDE) $(RM) $(OBJS)
	$(HIDE) $(RM) $(BONUS_OBJ)
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

git:
	@git add .
	@read -p "Insert the commit message: " TAG && git commit -m "$$TAG"
	@git push
	@echo "$(PURPLE)$(CBOLD) .      .      .      .      .      .      .      .      .      .      ."
	@echo ".  $(PURPLE)$(NAME) is entering the git world$(CEND)$(PURPLE)$(CBOLD)  .       .       .       .    . "
	@echo "   .        .        .        .        .        .        .        .        ."
	@echo "     .         .         .        _......____._        .         ."
	@echo "   .          .          . ..--°¨¨ .           ¨¨¨¨¨¨---...          ."
	@echo "                   _...--¨¨        ................       °-.              ."
	@echo "                .-°        ...:°::::;:::%:.::::::_;;:...     °-."
	@echo "             .-°       ..::::°°°°°   _...---°¨¨¨¨:::+;_::.      °.      ."
	@echo "  .        .° .    ..::::°      _.-¨¨               :::)::.       °."
	@echo "         .      ..;:::°     _.-°         .             f::°::    o  $(GREEN)_$(CEND)$(PURPLE)$(CBOLD)"
	@echo "        /     .:::%°  .  .-¨                        $(BLUE).-.$(CEND)$(PURPLE)$(CBOLD)  ::;;:.   $(GREEN)/¨ ¨x$(CEND)$(PURPLE)$(CBOLD)"
	@echo "  .   .°  ¨¨::.::°    .-¨     _.--°¨¨¨-.           $(BLUE)(   )$(CEND)$(PURPLE)$(CBOLD)  ::.::  $(GREEN)|_.-° |$(CEND)$(PURPLE)$(CBOLD)"
	@echo "     .°    ::;:°    .°     .-¨ $(YELLOW).d@@b.$(CEND)$(PURPLE)$(CBOLD)   \    .    . $(BLUE)°-°$(CEND)$(PURPLE)$(CBOLD)   ::%::   $(GREEN)\_ _/$(CEND)$(PURPLE)$(CBOLD)    ."
	@echo "    .°    :,::°    /   . _°    $(YELLOW)8@@@@8$(CEND)$(PURPLE)$(CBOLD)   j      .-°       :::::      $(GREEN)¨$(CEND)$(PURPLE)$(CBOLD) o"
	@echo "    | .  :.%:° .  j     $(RED)(_)$(CEND)$(PURPLE)$(CBOLD)    $(YELLOW)°@@@P°$(CEND)$(PURPLE)$(CBOLD)  .°   .-¨         ::.::    .  f"
	@echo "    |    ::::     (        -..____...-°  .-¨          .::::°       /"
	@echo ".   |    °:°::    °.                ..--°        .  .::°::   .    /"
	@echo "    j     °:::::    °-._____...---¨¨             .::%:::°       .°  ."
	@echo "     \      ::.:%..             .       .    ...:,::::°       .°"
	@echo " .    \       °:::°:..                ....::::.::::°       .-°          ."
	@echo "       \    .   °°:::%::°::.......:::::%::.::::°°       .-°"
	@echo "      . °.        . °°::::::%::::.::;;:::::°°°      _.-°          ."
	@echo "  .       °-..     .    .   °°°°°°°°°         . _.-°     .          ."
	@echo "         .    ¨¨--...____    .   ______......--° .         .         ."
	@echo "  .        .        .    ¨¨¨¨¨¨¨¨     .        .        .        .        ."
	@echo " .       .       .       .       .       .       .       .       ."
	@echo "     .      .      .      .      .      .      .      .      .      .      .$(CEND)"
	@echo "\n$(YELLOW)$(NAME) committed sucessfully$(CEND)"

norm:
	@norminette $(SRCS) $(BONUS_SRCS) ./includes/*.h ./includes/**/*.h ./includes/my_lib/

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[0;36m
CEND = \033[0m
CBOLD     = \033[1m
.PHONY: all clean fclean re 
