# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbazire <tbazire@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 11:12:59 by tbazire           #+#    #+#              #
#    Updated: 2014/01/04 18:09:17 by sconso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC		=	gcc
CFLAGS	+=	-Wall -Werror -Wextra -I include/ -I libft/includes/
LFLAGS	+=	-L libft/ -lft

FILESRC	=	main.c			\
			ft_utilities.c	\
			ft_pipex.c		\

DIRSRC	=	src
DIROBJ	=	.obj

SRC		=	$(addprefix $(DIRSRC)/, $(FILESRC))
OBJ		=	$(addprefix $(DIROBJ)/, $(SRC:.c=.o))

.PHONY: all clean fclean re

.SILENT :

all		:	$(NAME)

$(addprefix $(DIROBJ)/, %.o)	:	%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	@/bin/echo -n "Create object in $(addprefix $(DIROBJ)/, $(DIRSRC)): "
	@echo "\033[1;33m$(subst $(DIRSRC)/, , $(<:.c=.o))\033[0m"

$(NAME)		:	libft $(DIROBJ) $(OBJ)
	@make -C libft/ all
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $(OBJ)
	@echo "Binary name \033[4;32m$@\033[0m"

$(DIROBJ)	:
	@/bin/mkdir $(DIROBJ);				\
	for DIR in $(DIRSRC);				\
	do									\
		/bin/mkdir $(DIROBJ)/$$DIR;		\
	done								\

clean	:
	@/bin/rm -rf $(DIROBJ) a.out.dSYM
	@/bin/rm -f a.out
	@echo "Remove \033[1;30m$(DIROBJ)\033[0m"

fclean	:	clean
	@/bin/rm -f $(NAME)
	@echo "Remove \033[1;30m$(NAME)\033[0m"

# Change to -Weverything with new GCC
every	:	CFLAGS += -W
every	:	re

debug	:	CFLAGS	+= -g
debug	:	re

libft	:
	@make -C libft/ all

libfclean	:
	@make -C libft/ fclean

libre	:
	@make -C libft/ re
	@make re

re		:	fclean all
