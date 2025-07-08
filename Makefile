###############################################################################
#                                                                             #
#                                                                             #
#          █████████  █████  █████ ███████████   ████████  ██████████         #
#         ███░░░░░███░░███  ░░███ ░░███░░░░░███ ███░░░░███░░███░░░░███        #
#        ███     ░░░  ░███   ░███  ░███    ░███░░░    ░███ ░███   ░░███       #
#       ░███          ░███   ░███  ░██████████    ██████░  ░███    ░███       #
#       ░███          ░███   ░███  ░███░░░░░███  ░░░░░░███ ░███    ░███       #
#       ░░███     ███ ░███   ░███  ░███    ░███ ███   ░███ ░███    ███        #
#        ░░█████████  ░░████████   ███████████ ░░████████  ██████████         #
#         ░░░░░░░░░    ░░░░░░░░   ░░░░░░░░░░░   ░░░░░░░░  ░░░░░░░░░░          #
#                                                                             #
#                                                                             #
###############################################################################

CC 			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunused
MLX_FLAGS	:= -ldl -lglfw -pthread -lm

LIBFT_PATH	:= ./libft
LIBFT		:= $(LIBFT_PATH)/libft.a
MLX42_PATH	:= ./MLX42
MLX42		:= $(MLX42_PATH)/build/libmlx42.a

################################ MANDATORY ####################################

NAME		:= cub3D

HEADERS		:= -I ./mandatory/inc -I ./MLX42/include/MLX42/
SRCS_PATH	:= ./mandatory/src
OBJS_PATH	:= ./obj

PARSING		:= get_map config map_val
MAIN		:= main errors
GAME		:= image hook_and_loop movements render_image ray_cast
UTILS		:= lst_utils utils free parsing_utils graphic_utils game_utils

SRCS	:= $(addsuffix .c, $(addprefix mandatory/src/, $(MAIN))) \
			$(addsuffix .c, $(addprefix mandatory/src/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix mandatory/src/utils/, $(UTILS))) \
			$(addsuffix .c, $(addprefix mandatory/src/game/, $(GAME)))

OBJS := $(addprefix $(OBJS_PATH)/, $(notdir $(SRCS:.c=.o)))

################################## BONUS ######################################

NAME_B		:= cub3D_bonus

HEADERS_B	:= -I ./bonus/inc -I ./MLX42/include/MLX42/
SRCS_PATH_B	:= ./bonus/src
OBJS_PATH_B	:= ./obj_bonus

PARSING_B	:= get_map_bonus config_bonus map_val_bonus
MAIN_B		:= main_bonus errors_bonus
GAME_B		:= enemy_bonus enemy_utils_bonus image_bonus \
				hook_and_loop_bonus minimap_bonus minimap_utils_bonus \
				movements_bonus render_image_bonus ray_cast_bonus
UTILS_B		:= lst_utils_bonus utils_bonus free_bonus parsing_utils_bonus \
				graphic_utils_bonus game_utils_bonus

SRCS_B	:= $(addsuffix .c, $(addprefix bonus/src/, $(MAIN_B))) \
			$(addsuffix .c, $(addprefix bonus/src/parsing/, $(PARSING_B))) \
			$(addsuffix .c, $(addprefix bonus/src/utils/, $(UTILS_B))) \
			$(addsuffix .c, $(addprefix bonus/src/game/, $(GAME_B))) \

OBJS_B		:= $(addprefix $(OBJS_PATH_B)/, $(notdir $(SRCS_B:.c=.o)))

################################ MANDATORY ####################################

all: $(NAME)

$(NAME): $(MLX42_PATH) $(MLX42) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME)
	@echo "\033[1;95m💻 $(NAME) building completed...\033[0m"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: | $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -c $(filter %/$*.c, $(SRCS)) -o $@

################################## BONUS ######################################

bonus: $(NAME_B)

$(NAME_B): $(MLX42_PATH) $(MLX42) $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_B) $(LIBFT) $(MLX42) -o $(NAME_B)
	@echo "\033[1;95m💻 $(NAME_B) building completed...\033[0m"

$(OBJS_PATH_B):
	@mkdir -p $(OBJS_PATH_B)

$(OBJS_PATH_B)/%.o: | $(OBJS_PATH_B)
	@$(CC) $(CFLAGS) $(HEADERS_B) -c $(filter %/$*.c, $(SRCS_B)) -o $@

###############################################################################

$(MLX42_PATH):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_PATH)
	@echo "\033[1;93m⬇️  MLX downloading finished...\033[0m"

$(MLX42):
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build > /dev/null 2>&1 && make -C \
		$(MLX42_PATH)/build -j4 > /dev/null 2>&1
	@echo "\033[1;96m📦 MLX42 building completed...\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "\033[1;96m📦 LIBFT building completed...\033[0m"

###############################################################################

clean:
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJS_PATH_B)
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@echo "\033[1;97m💦💧  Cleaning completed... \033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

f_mlx_clean: fclean
	@rm -rf $(MLX42_PATH)
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

re: fclean all

.PHONY: all clean fclean f_mlx_clean re bonus
