#include "cub3d.h"

void	close_hook(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	printf("Window has been closed\n");
	mlx_close_window(game->mlx);
	free_game(game);
}

void	esc_hook(mlx_key_data_t input, void *data)
{
	t_game	*game;

	(void)input;
	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		printf("Escape key pressed\n");
		mlx_close_window(game->mlx);
		free_game(game);
	}
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_movement(game);
	handle_mouse_rotation(game);
	render_scene(game);
}
