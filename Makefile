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

CC = cc
CFLAGS		:= -Wextra -Wall -Werror -Wunused
MLX_FLAGS	:= -ldl -lglfw -pthread -lm

HEADERS		:= -I ./inc -I ./MLX42/include/MLX42/

SRCS_PATH	:= ./src
OBJS_PATH	:= ./obj
LIBFT_PATH	:= ./libft
LIBFT		:= $(LIBFT_PATH)/libft.a
MLX42_PATH	:= ./MLX42
MLX42		:= $(MLX42_PATH)/build/libmlx42.a

PARSING		:= get_map

#INIT		:= 

MAIN		:= main errors

#SMTHNG		:= 

UTILS		:= lst_utils

SRCS	:= $(addsuffix .c, $(addprefix src/, $(MAIN))) \
			$(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) \
			$(addsuffix .c, $(addprefix src/utils/, $(UTILS)))
#			$(addsuffix .c, $(addprefix src/builtins/, $(BUILTINS))) \
#			$(addsuffix .c, $(addprefix src/tokenization/, $(TOKENS))) \


OBJS		:= $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

all: $(NAME)

$(NAME): $(MLX42_PATH) $(MLX42) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(HEADERS) $(LIBFT) $(MLX42) -o $(NAME) -lreadline 
#-fsanitize=address
	@echo "\033[1;95m💻 $(NAME) building completed...\033[0m"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MLX42_PATH):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_PATH)
	@echo "\033[1;93m⬇️  MLX downloading finished...\033[0m"

$(MLX42):
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build > /dev/null 2>&1 && make -C $(MLX42_PATH)/build -j4 > /dev/null 2>&1
	@echo "\033[1;96m📦 MLX42 building completed...\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "\033[1;96m📦 LIBFT building completed...\033[0m"

clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@echo "\033[1;97m💦💧  Cleaning completed... \033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

f_mlx_clean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX42_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@echo "\033[1;97m🧽🫧  Force cleaning completed... \033[0m"

re: fclean all

.PHONY: all clean fclean re norm
