# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 16:48:13 by norban            #+#    #+#              #
#    Updated: 2024/10/07 18:05:27 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = srcs/main.c \
	   srcs/ft_strlen.c \
	   srcs/ft_putchar.c \
	   srcs/ft_display_file.c \
	   srcs/ft_input_valid.c \
	   srcs/ft_putstr.c

CFLAGS = -Wall -Wextra -Werror 

OBJECTS = $(SRCS:.c=.o)

INCS_DIR = ./include/

NAME = ft_display_file

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS_DIR)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:
	re make all fclean clean
