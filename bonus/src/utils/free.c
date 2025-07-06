#include "cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_parsing(t_game *game)
{
	if (game->no_path)
		free(game->no_path);
	if (game->so_path)
		free(game->so_path);
	if (game->we_path)
		free(game->we_path);
	if (game->ea_path)
		free(game->ea_path);
	if (game->player)
		free(game->player);
	if (game->map)
		free_arr(game->map);
}

void	free_game(t_game *game)
{
	int	i;

	free_parsing(game);
	i = 0;
	free(game->enemies);
	if (game->unicorn_amount)
		free(game->unicorn_amount);
	mlx_terminate(game->mlx);
	exit(0);
}
