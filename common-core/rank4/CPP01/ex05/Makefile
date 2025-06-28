CC = g++

NAME		= Harl

INC			= include
CFLAGS		= -Wall -Wextra -Werror -std=c++98
MAKE_LIB	= make_lib


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

SRC_LIST	= 	Harl.cpp \
				main.cpp

OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.cpp=.o))

all:		$(OBJ_DIR) $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -I $(INC) -o $(NAME)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) compiled ✅$(DEF_COLOR)"

re:			fclean all

clean:
			@echo "$(YELLOW)📦 Cleaning object files $(DEF_COLOR)"
			@rm -rf $(OBJ_DIR)/*.o
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@echo "🗑 $(YELLOW) Cleaning $(NAME) $(DEF_COLOR)"
			@rm -f $(NAME)
			@rm -rf $(OBJ_DIR)
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) files cleaned ✅$(DEF_COLOR)"

$(OBJ_DIR)%.o: %.cpp
			@echo "$(YELLOW)📦 Compiling $< $(DEF_COLOR)"
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

.PHONY:		all clean fclean re