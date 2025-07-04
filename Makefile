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

NAME		:= cub3D
NAME_B		:= cub3D_bonus

CC 			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunused
MLX_FLAGS	:= -ldl -lglfw -pthread -lm

HEADERS		:= -I ./mandatory/inc -I ./MLX42/include/MLX42/
HEADERS_B	:= -I ./bonus/inc -I ./MLX42/include/MLX42/

SRCS_PATH	:= ./mandatory/src
SRCS_PATH_B	:= ./bonus/src
OBJS_PATH	:= ./obj
OBJS_PATH_B	:= ./obj_bonus
LIBFT_PATH	:= ./libft
LIBFT		:= $(LIBFT_PATH)/libft.a
MLX42_PATH	:= ./MLX42
MLX42		:= $(MLX42_PATH)/build/libmlx42.a

PARSING		:= get_map config map_val

MAIN		:= main errors

GAME		:= image hook_and_loop movements render_image minimap ray_cast

BONUS		:= image hook_and_loop movements render_image minimap minimap_utils ray_cast enemy enemy_utils

UTILS		:= lst_utils utils free parsing_utils graphic_utils

SRCS	:= $(addsuffix .c, $(addprefix mandatory/src/, $(MAIN))) \
			$(addsuffix .c, $(addprefix mandatory/src/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix mandatory/src/utils/, $(UTILS))) \
			$(addsuffix .c, $(addprefix mandatory/src/game/, $(GAME)))

SRCS_B	:= $(addsuffix .c, $(addprefix bonus/src/, $(MAIN))) \
			$(addsuffix .c, $(addprefix bonus/src/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix bonus/src/utils/, $(UTILS))) \
			$(addsuffix .c, $(addprefix bonus/src/game/, $(BONUS))) \

OBJS		:= $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
OBJS_B		:= $(SRCS_B:$(SRCS_PATH_B)/%.c=$(OBJS_PATH_B)/%.o)

all: $(NAME)

$(NAME): $(MLX42_PATH) $(MLX42) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(HEADERS) $(LIBFT) $(MLX42) -o $(NAME)
	@echo "\033[1;95m💻 $(NAME) building completed...\033[0m"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH_B):
	@mkdir -p $(OBJS_PATH_B)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJS_PATH_B)/%.o: $(SRCS_PATH_B)/%.c | $(OBJS_PATH_B)
	@$(CC) $(CFLAGS) $(HEADERS_B) -c $< -o $@

$(MLX42_PATH):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_PATH)
	@echo "\033[1;93m⬇️  MLX downloading finished...\033[0m"

$(MLX42):
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build > /dev/null 2>&1 && make -C $(MLX42_PATH)/build -j4 > /dev/null 2>&1
	@echo "\033[1;96m📦 MLX42 building completed...\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "\033[1;96m📦 LIBFT building completed...\033[0m"

bonus: $(MLX42_PATH) $(MLX42) $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_B) $(HEADERS_B) $(LIBFT) $(MLX42) -o $(NAME_B)
#-fsanitize=address
	@echo "\033[1;95m💻 $(NAME_B) building completed...\033[0m"

clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@echo "\033[1;97m💦💧  Cleaning completed... \033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

f_mlx_clean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@rm -rf $(MLX42_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

re: fclean all

.PHONY: all clean fclean re norm bonus
