CC = cc

NAME		= so_long

INC			= include
INC_LIBFT	= libft/include
CFLAGS		= -Wall -Wextra -g
MLXFLAGS	= -lXext -lX11 -lm -lz

LIBFT		= libft
LIBFT_A		= libft/libft.a
MLX			= mlx_linux
MLX_A		= mlx_linux/libmlx_Linux.a
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

SRC_LIST	= 	so_long.c \
				game_manager.c \
				image_manager.c \
				menu.c \
				cursor.c \
				character.c \
				collectible.c \
				exit.c \
				image_creator.c \
				ingame.c \
				create_map.c \
				create_map_utils.c \
				map_checker.c \
				map_road_checker.c \
				map_road_checker_2.c \
				character_collision.c \
				free_all.c \

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

all:		$(OBJ_DIR) $(NAME)

$(NAME):	logo $(MAKE_LIB) $(OBJS)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS) $(LIBFT_A) $(MLX_A) -o $(NAME) $(MLXFLAGS)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) compiled ✅$(DEF_COLOR)"

re:			fclean all

clean:
			@echo " 🗑 $(YELLOW) Cleaning $(LIBFT) $(DEF_COLOR)"
			@make clean --no-print-directory -C $(LIBFT)
			@echo " 🗑 $(YELLOW) Cleaning $(MLX) $(DEF_COLOR)"
			@make clean --no-print-directory -C $(MLX)

fclean:		clean
			@echo " 🗑 $(YELLOW) Cleaning $(NAME) $(DEF_COLOR)"
			@rm -rf $(OBJ_DIR)
			@make fclean --no-print-directory -C $(LIBFT)
			@echo ""
			@echo "$(GREEN)$(BOLD)		✅ $(NAME) files cleaned ✅$(DEF_COLOR)"

logo:
			@cat logo.txt

$(MAKE_LIB):
			@echo "		📚 $(CYAN)$(BOLD) Compiling $(MLX) 📚$(DEF_COLOR)"
			@echo ""
			@make --no-print-directory -w -C $(MLX)
			@echo "		📚 $(CYAN)$(BOLD) Compiling $(LIBFT) 📚$(DEF_COLOR)"
			@echo ""
			@make --no-print-directory -C $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c test
			@echo "$(YELLOW)📦 Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -I $(MLX) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

test:
			@echo "		💾$(CYAN)$(BOLD) Compiling $(NAME) $(DEF_COLOR)💾"
			@echo ""

.PHONY:		all clean fclean re