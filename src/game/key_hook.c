#include "cub3d.h"

void	key_hook(mlx_key_data_t input, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		printf("Escape key pressed\n");
		mlx_close_window(game->mlx);
	}
	if (input.key == MLX_KEY_S && input.action == MLX_PRESS)
		printf("Down key pressed\n");
	if (input.key == MLX_KEY_A && input.action == MLX_PRESS)
		printf("Left key pressed\n");
	if (input.key == MLX_KEY_W && input.action == MLX_PRESS)
		printf("Up key pressed\n");
	if (input.key == MLX_KEY_D && input.action == MLX_PRESS)
		printf("Right key pressed\n");
	if (input.key == MLX_KEY_LEFT && input.action == MLX_PRESS)
		printf("Left arrow key pressed\n");
	if (input.key == MLX_KEY_RIGHT && input.action == MLX_PRESS)
		printf("Right arrow key pressed\n");
}