# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 12:21:47 by ajordan-          #+#    #+#              #
#    Updated: 2025/01/09 17:03:14 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= push_swap
BNAME		= checker
INC			= inc
HEADER		= -I include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g 
FSANITIZE	= -fsanitize=address -g3
RM			= rm -f
ECHO		= echo -e

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

PSW_DIR		=	push_swap/
MAND_FILES	=	checksort push_swap stack_sort quicksort create_tab get_median stack_median_sort smallstacksort stack_manager
COMM_DIR	=	common/
COMM_FILES	=	swap rotate reverse_rotate push
BONUS_DIR	=	bonus/
BONUS_FILES	=	checksort printchecksort checker create_tab stack_manager quicksort

SRC_FILES	=	$(addprefix $(PSW_DIR), $(MAND_FILES))
COM_FILES	=	$(addprefix $(COMM_DIR), $(COMM_FILES))
SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

COMMON 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(COM_FILES)))
COBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(COM_FILES)))

BSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

OBJF		=	.cache_exists

start:
			@$(ECHO) -n "$(YELLOW)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make all --no-print-directory

all:		$(NAME)

$(NAME):	$(OBJ) $(COBJ) $(OBJF)
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => 100%$(DEF_COLOR)\n"
			@make -C $(LIBFT) --no-print-directory
			@cp libft/libft.a .
			@cp libft/include/libft.h ./include
			@$(ECHO) -n "$(YELLOW)[$(NAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ) $(COBJ) $(HEADER) libft.a -o $(NAME)
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(PSW_DIR)
			@mkdir -p $(OBJ_DIR)$(COMM_DIR)
			@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean --no-print-directory -C $(LIBFT)
			@$(ECHO) -n "$(BLUE)[push_swap]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(RM) $(OBJF)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@rm -rf *.dSYM
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[push_swap]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [push_swap]!$(DEF_COLOR)\n"

bonus:
			@$(ECHO) -n "$(YELLOW)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make allbonus --no-print-directory

allbonus:		$(BNAME)

$(BNAME):	$(BOBJ) $(COBJ)
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => 100%$(DEF_COLOR)\n"
			@make -C $(LIBFT) --no-print-directory
			@cp libft/libft.a .
			@$(ECHO) -n "$(YELLOW)[$(BNAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(BSRC) $(COMMON) $(HEADER) libft.a -o $(BNAME)
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

norm:
			@clear
			@norminette $(SRC) $(INLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
