/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:43 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 15:21:06 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_paths(t_game *game)
{
	int	fd;

	fd = open(game->no_path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(game->so_path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(game->we_path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(game->ea_path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	init_game(t_game *game)
{
	if (check_paths(game) != 0)
		return (free_parsing(game), err_msg(ERR_PATH), 1);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		return (free_parsing(game), err_msg(ERR_MLXINIT), 1);
	if (upload_wall_textures(game) != 0)
		return (free_game(game), 1);
	init_player(game);
	game->rays = NULL;
	game->mouse_initialized = 0;
	game->prev_mouse_x = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERR_USAGE), 1);
	if (get_map(&game, argv[1]) < 0)
		return (1);
	if (init_game(&game) != 0)
		return (1);
	if (init_image(&game) == 1)
	{
		err_msg(INIT_IMAGE);
		free_game(&game);
	}
	mlx_key_hook(game.mlx, esc_hook, &game);
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
