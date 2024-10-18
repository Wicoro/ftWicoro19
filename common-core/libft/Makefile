# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 09:40:12 by norban            #+#    #+#              #
#    Updated: 2024/10/18 11:20:13 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = ft_islower.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_isupper.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

SRCS_B = ft_lstiter_bonus.c \
	     ft_lstmap_bonus.c \
		 ft_lstnew_bonus.c \
		 ft_lstadd_front_bonus.c \
		 ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c \
		 ft_lstadd_back_bonus.c \
		 ft_lstdelone_bonus.c \
		 ft_lstclear_bonus.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

BONUS = $(SRCS_B:.c=.o)

INCS_DIR = /includes/

NAME = libft.a

all: $(NAME)

bonus: $(OBJECTS) $(BONUS)
		ar rc $(NAME) $(OBJECTS) $(BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS_DIR)

$(NAME): $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS) $(BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:
	re make all fclean clean bonus
