# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 23:53:16 by norban            #+#    #+#              #
#    Updated: 2024/10/07 10:56:36 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = srcs/do-op.c srcs/ft_atoi.c srcs/ft_putnbr.c

CFLAGS = -Wall -Wextra -Werror

NAME = do-op

all: 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:
	re make all fclean clean
