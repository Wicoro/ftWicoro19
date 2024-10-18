# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 23:53:16 by norban            #+#    #+#              #
#    Updated: 2024/07/22 20:39:22 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = srcs/ft_putnbr.c \
	   srcs/main.c \
	   srcs/ft_strlen.c \
	   srcs/ft_split.c \
	   srcs/ft_putstr.c \

CFLAGS = -Wall -Wextra -Werror

CFLAGSD = -g -fsanitize=address -ggdb

NAME = bsq

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

alld:
	$(CC) $(CFLAGS) $(CFLAGSD) $(SRCS) -o $(NAME)

clean:
		rm -f $(NAME)

.PHONY:
	re make all fclean clean
