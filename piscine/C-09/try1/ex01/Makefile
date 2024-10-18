# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 17:09:28 by norban            #+#    #+#              #
#    Updated: 2024/07/18 18:33:39 by norban           ###   ########.fr        #
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
