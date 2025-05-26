
#include "cub3d.h"

int	file_check(char *fname)
{
	return (!ft_strchr(fname, '.')
		|| ft_strncmp((ft_strrchr(fname, '.')), ".cub\0", 5));
}

bool	if_inside(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	free_game(t_game *game)
{

	if (game->background)
		mlx_delete_image(game->mlx, game->background);
	if (game->texture[NORTH])
		mlx_delete_texture(game->texture[NORTH]);
	if (game->texture[SOUTH])
		mlx_delete_texture(game->texture[SOUTH]);
	if (game->texture[WEST])
		mlx_delete_texture(game->texture[WEST]);
	if (game->texture[EAST])
		mlx_delete_texture(game->texture[EAST]);
	if (game->ceiling)
		free(game->ceiling);
	if (game->floor)
		free(game->floor);
	if (game->no_path)
		free(game->no_path);
	if (game->so_path)
		free(game->so_path);
	if (game->we_path)
		free(game->we_path);
	if (game->ea_path)
		free(game->ea_path);
	// free(game);
}
