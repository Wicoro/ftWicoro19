# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 16:48:13 by norban            #+#    #+#              #
#    Updated: 2024/10/08 09:32:59 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_swap.c srcs/ft_strlen.c srcs/ft_strcmp.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

INCS_DIR = ./includes/

NAME = libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS_DIR)

$(NAME): $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:
	re make all fclean clean
