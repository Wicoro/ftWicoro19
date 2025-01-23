# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 09:40:12 by norban            #+#    #+#              #
#    Updated: 2025/01/22 16:43:25 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME		=	libft.a
INCLUDES	=	include/
SRC_DIR 	=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper atoi_too_big

FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr ft_free_split \
				get_next_line get_next_line_utils

FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC_FILES+=$(FTIS)
SRC_FILES+=$(FTMEM)
SRC_FILES+=$(FTPUT)
SRC_FILES+=$(FTTO)
SRC_FILES+=$(FTSTR)
BONUS_FILES+=$(FTLST)

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))


###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus:		$(BONUS_OBJ)
			@$(AR) $(NAME) $(BONUS_OBJ)
			@echo "$(GREEN)Libft bonus compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)
			@echo "$(BLUE)Libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
