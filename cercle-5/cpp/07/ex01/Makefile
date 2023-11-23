#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I.
RM		=	rm -rf
OBJDIR	=	bin/
SRCDIR	=	src/

# Dir and file names
NAME	=	ex01
SRCS	=	main.cpp
# OBJS	=	$(SRCS:.cpp=.o)
OBJS		= $(addprefix bin/, ${SRCS:.cpp=.o})
# OBJS		= $(subst ./, bin, $(SRCS:.c=.o))
# OBJS	=	$(patsubst $(SRCDIR),$(OBJDIR)%.o,$(SRCS))
DEP		=	$(wildcard *.hpp)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) compiled!$(CEND)"

bin/%.o: 	$(SRCDIR)%.cpp $(DEP)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[0;36m
CEND = \033[0m
CBOLD     = \033[1m

.PHONY: all bonus clean fclean re