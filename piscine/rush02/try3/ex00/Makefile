# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 23:53:16 by norban            #+#    #+#              #
#    Updated: 2024/07/21 12:16:50 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = srcs/create_dictionnary.c \
	   srcs/main.c \
	   srcs/ft_strlen.c \
	   srcs/ft_split.c \
	   srcs/ft_print_nb.c \
	   srcs/ft_printers.c \
	   srcs/ft_putstr.c \
	   srcs/ft_atoi.c \
	   srcs/ft_putchar.c

CFLAGS = -Wall -Wextra -Werror

CFLAGSD = -g -fsanitize=address -ggdb

NAME = rush02

all: 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

alld:
	$(CC) $(CFLAGS) $(CFLAGSD) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:
	re make all fclean clean
