CC = cc

NAME		= minishell

INC			= include
INC_LIBFT	= libft/include
CFLAGS		= -Wall -Wextra -g3 -Werror #-fsanitize=address
RL_FLAGS	= -lreadline
LIBFT		= libft
LIBFT_A		= libft/libft.a
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

SRC_LIST	= 	minishell.c \
				parsing/lexer.c \
				parsing/lexer_to_cmds.c \
				parsing/create_cmd.c \
				parsing/create_cmd_utils.c \
				parsing/parser.c \
				parsing/heredoc.c \
				parsing/heredoc_utils.c \
				parsing/heredoc_utils2.c \
				parsing/var_expander.c \
				parsing/var_expander_utils.c \
				parsing/var_exchanger.c \
				utils/env_utils.c \
				utils/env_utils2.c \
				utils/get_env.c \
				utils/free_utils.c \
				utils/free_utils2.c \
				exec/exec.c \
				exec/exec_utils.c \
				exec/exec_utils2.c \
				exec/pipe_handler.c \
				exec/process_handler.c \
				exec/process_child_handler.c \
				exec/pipe_utils.c \
				exec/output_handler.c \
				exec/input_handler.c \
				built_in/env.c \
				built_in/unset.c \
				built_in/export.c \
				built_in/export_utils.c \
				built_in/pwd.c \
				built_in/cd.c \
				built_in/echo.c \
				built_in/exit.c \
				built_in/exit_utils.c \
				signal/signal_parent.c \
				signal/signal_parent2.c \
				signal/signal_child.c \

# BONUS_LIST	=

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

# SRCS_BONUS	=	$(addprefix $(BONUS_DIR), $(BONUS_LIST))
# OBJS_BONUS	= 	$(addprefix $(BOBJ_DIR), $(BONUS_LIST:.c=.o))


all:		$(OBJ_DIR) $(NAME)

$(NAME):	logo $(MAKE_LIB) $(OBJS)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS) $(LIBFT_A) -o $(NAME) $(RL_FLAGS)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) compiled ✅$(DEF_COLOR)"

# bonus:		logo $(MAKE_LIB) $(OBJS_BONUS)
# 			@$(CC) $(CFLAGS) -I $(INC) $(OBJS_BONUS) $(LIBFT_A) -o $(NAME)
# 			@echo ""
# 			@echo "$(GREEN)$(BOLD)		✅ $(NAME)_bonus compiled ✅$(DEF_COLOR)"

re:			fclean all

clean:
			@echo " 🗑 $(YELLOW) Cleaning $(LIBFT) $(DEF_COLOR)"
			@make clean --no-print-directory --silent -C $(LIBFT)

fclean:		clean
			@echo " 🗑 $(YELLOW) Cleaning $(NAME) $(DEF_COLOR)"
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make fclean --no-print-directory -C $(LIBFT)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) files cleaned ✅$(DEF_COLOR)"

logo:
			@cat logo.txt

$(MAKE_LIB):
			@echo "		📚 $(CYAN)$(BOLD) Compiling $(LIBFT) 📚$(DEF_COLOR)"
			@echo ""
			@make --no-print-directory --silent -C $(LIBFT)
			@echo "		💾$(CYAN)$(BOLD) Compiling $(NAME) $(DEF_COLOR)💾"
			@echo ""

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(YELLOW) 📦 Compiling $< $(DEF_COLOR)"
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(BOBJ_DIR)%.o: $(BONUS_DIR)%.c
			@echo "$(YELLOW) 📦 Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -c $< -o $@

$(BOBJ_DIR):
			@mkdir -p $(BOBJ_DIR)

.PHONY:		all clean fclean re
