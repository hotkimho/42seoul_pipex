# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:45:41 by hkim2             #+#    #+#              #
#    Updated: 2022/02/26 17:48:17 by hkim2            ###   ########.fr        #
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
	

SRCS = $(addprefix src/, $(FUNC))
#OBJS = $(addsuffix .o, $(FUNC))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(SRCS) -L $(LIB_DIR) -lft -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : bonus all clean fclean re