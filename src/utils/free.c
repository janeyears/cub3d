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
	if (game->texture[NORTH])
		mlx_delete_texture(game->texture[NORTH]);
	if (game->texture[SOUTH])
		mlx_delete_texture(game->texture[SOUTH]);
	if (game->texture[WEST])
		mlx_delete_texture(game->texture[WEST]);
	if (game->texture[EAST])
		mlx_delete_texture(game->texture[EAST]);
	free_parsing(game);
}
