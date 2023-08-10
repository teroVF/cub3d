#Standard

NAME = cub3D
CC = cc
LIBFT = ./lib/libft/libft.a
MLX = ./lib/mlx/libmlx_Linux.a
LIB = -L./lib/mlx -L./lib/libft -lft -lmlx_Linux -lXext -lX11 -lm
SRC_PATH = src/
OBJ_PATH = obj/
bonus_PATH = bonus/
CFLAGS = -Wall -Werror -Wextra -g
DEBUG = -fsanitize=address
DEBUG_T = -fsanitize=thread
PERFORMANCE = -O3 -march=native -flto -funroll-loops
RM = rm -fr

#Sources
FILES        =     	main render vector1 vector2 dda hooks \
					utils parse parse_utils parse_map \
					clean_exit raycasting player_position

# BONUS_FILES	=		

CUB3D_SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
CUB3D_OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
INCS = -I./includes 

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

all: $(NAME)

#MANDATORY
$(NAME):			$(LIBFT) $(MLX) $(CUB3D_OBJ)
						@echo "$(YELLOW) Compiling: $@ $(DEF_COLOR)"
						@$(CC) $(INCS) $(CFLAGS) -O3 $(CUB3D_OBJ) $(LIB) -o $@

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
						@mkdir -p $(OBJ_PATH)
						@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
						@$(CC) $(INCS) $(CFLAGS) -c $< -o $@

$(LIBFT):
						@make -C ./lib/libft

$(MLX):
						@make -C ./lib/mlx

clean:
						@$(RM) $(OBJ_PATH)
						@echo "$(BLUE)All objects files cleaned!$(DEF_COLOR)"

fclean: 			clean
						@$(RM) $(NAME)
						@make -C ./lib/libft/ fclean
						@make -C ./lib/mlx/ clean
						@echo "$(CYAN)All executable files cleaned!$(DEF_COLOR)"

re: 				fclean all
						@echo "$(GREEN)Cleaned and rebuilt everything$(DEF_COLOR)"

.PHONY: 			fclean all re clean
