# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:45:41 by hkim2             #+#    #+#              #
#    Updated: 2022/03/06 19:03:10 by hkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIB_DIR = ./lib/

FUNC =	main.c\
		child.c\
		error.c\
		parser.c\
		pipe.c\
		read_file.c\

BONUS_FUNC =	main_bonus.c\
				child_bonus.c\
				error_bonus.c\
				parser_bonus.c\
				pipe_bonus.c\
				read_file_bonus.c\

SRCS = $(addprefix src/, $(FUNC))
OBJS = $(SRCS:c=o)

BONUS_SRCS = $(addprefix bonus/, $(BONUS_FUNC))
BONUS_OBJS = $(BONUS_SRCS:c=o)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -L $(LIB_DIR) -lft -o $(NAME) $^
	
all : $(NAME)

bonus :	$(BONUS_OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -L $(LIB_DIR) -lft -o $(NAME) $^
	
clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : bonus all clean fclean re