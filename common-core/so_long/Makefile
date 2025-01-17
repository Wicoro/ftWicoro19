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

SRC_DIR		= src/
OBJ_DIR		= obj/

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
				map_checker.c \
				map_road_checker.c \
				map_road_checker_2.c \
				character_collision.c \
				free_all.c \

SRCS		= 	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS		= 	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

all:		$(OBJ_DIR) $(NAME)

$(NAME):	$(OBJS)
			make -C $(MLX)
			make -C $(LIBFT)
			@$(CC) $(CFLAGS) -I $(INC) $(OBJS) $(LIBFT_A) $(MLX_A) -o $(NAME) $(MLXFLAGS)

re:			fclean all

clean:
			@make clean --no-print-directory -C $(LIBFT)
			@make clean --no-print-directory -C $(MLX)

fclean:		clean
			@rm -rf $(OBJ_DIR)
			@make fclean -C $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@$(CC) $(CFLAGS) -I $(INC) -I $(INC_LIBFT) -I $(MLX) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

.PHONY:		all clean fclean re