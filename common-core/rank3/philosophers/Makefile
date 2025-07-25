CC = cc

NAME		= philo

INC			= include
CFLAGS		= -Wall -Wextra -Werror -g  # -fsanitize=address  # -fsanitize=thread
MAKE_LIB	= make_lib

SRC_DIR		= src/
OBJ_DIR		= obj/

DEF_COLOR	=	\033[0;37m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

BOLD		=	\033[1m
UNDERLINE	=	\033[4m

SRC_LIST	= 	ft_atoi.c \
				philosophers.c \
				philosophers_manager.c \
				threads_manager.c \
				print_message.c \
				routine.c \
				free_all.c \
				fragmented_sleep.c \

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

all:		$(OBJ_DIR) $(NAME)

$(NAME):	logo $(MAKE_LIB) $(OBJS)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS) -o $(NAME)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) compiled ✅$(DEF_COLOR)"

re:			fclean all

clean:
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@echo " 🗑 $(YELLOW) Cleaning $(NAME) $(DEF_COLOR)"
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) files cleaned ✅$(DEF_COLOR)"
			@echo ""

logo:
			@cat logo.txt

$(MAKE_LIB):
			@echo "		💾$(CYAN)$(BOLD) Compiling $(NAME) $(DEF_COLOR)💾"
			@echo ""

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(YELLOW)📦 Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
	

.PHONY:		all clean fclean re