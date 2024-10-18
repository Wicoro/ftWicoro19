# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 23:53:16 by norban            #+#    #+#              #
#    Updated: 2024/07/24 21:17:22 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = srcs/ft_putnbr.c \
	   srcs/main.c \
	   srcs/ft_strlen.c \
	   srcs/ft_split.c \
	   srcs/ft_putstr.c \
	   srcs/ft_extract_board.c \
	   srcs/is_board_valid.c \
	   srcs/ft_atoi.c \
	   srcs/ft_substring.c \
	   srcs/ft_get_file.c \
	   srcs/ft_strjoin.c \
	   srcs/ft_extract_input_board.c \
	   srcs/ft_find_bsq.c \
	   srcs/ft_draw_bsq.c

INCS_DIR = ./includes/

CFLAGS = -Wall -Wextra -Werror

CFLAGSD = -g 

NAME = bsq

OBJ = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

alld: $(OBJ)
	@$(CC) $(CFLAGS) $(CFLAGSD) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

red: fclean alld

.PHONY:
	re make all fclean clean
