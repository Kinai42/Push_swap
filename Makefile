# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 20:37:45 by dbauduin          #+#    #+#              #
#    Updated: 2018/06/16 20:47:39 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********** #
# PRINT COLOR #
# *********** #
default	?=	\e[38;5;15m
green	?=	\e[38;5;47m
yellow	?=	\e[38;5;226m
orange	?=	\e[38;5;208m
red	?=	\e[38;5;196m
blue	?=	\e[38;5;45m
magenta	?=	\e[38;5;198m
violet	?=	\e[38;5;171m
purple	?=	\e[38;5;165m

C_DEF	?=	\e[38;5;15m
OK	?=	\e[38;5;47m
WARN 	?=	\e[38;5;208m
ERROR	?=	\e[38;5;196m

# *********** #
#    PATHS    #
# *********** #

.SILENT	:	NAME clean fclean all re obj libft
.PHONY	:	clean fclean all re obj libft

OBJ_W ?= $(shell find obj | grep \\.o$)

# *********** #
#  MAKEFILE   #
# *********** #

SLEEP ?= 0.

CC			?=	clang

CC_FLAG		?=	-Werror \
				-Wall	\
				-Wextra \

CC_FLAG++	?=	-Werror \
				-Wall	\
				-Wextra \
				-g -fsanitize=leak \

PROJECT		= PUSH_SWAP

NAME_CHECK	= checker
NAME_PUSH	= push_swap

OBJ_CHECK = $(addsuffix .o, $(addprefix obj/, checker))
OBJ_COMMUN = $(addsuffix .o, $(addprefix obj/, operator check_nbr))
OBJ_PUSH = $(addsuffix .o, $(addprefix obj/, push_swap resolver))

all: obj $(NAME_CHECK) $(NAME_PUSH)
	printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

$(NAME_CHECK): $(OBJ_CHECK) $(OBJ_COMMUN)
	@make -C libft
	@$(CC) $(CC_FLAG) -o $(NAME_CHECK) $(OBJ_CHECK) $(OBJ_COMMUN) libft/libft.a

$(NAME_PUSH): $(OBJ_PUSH) $(OBJ_COMMUN)
	@$(CC) $(CC_FLAG) -o $(NAME_PUSH) $(OBJ_PUSH) $(OBJ_COMMUN) libft/libft.a

obj/%.o: src/%.c
	@gcc -o $@ -c $< -I include -I libft/include

clean:
	@make	-C ./libft clean
	@rm -f	$(OBJ_W)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./obj$(C_DEF)\n"

fclean: clean
	@make	-C ./libft fclean
	@rm -f $(NAME_CHECK)
	printf "$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

re: fclean all
