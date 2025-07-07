/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:42 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:16:43 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		return (free_parsing(game), err_msg(ERR_MLXINIT), 1);
	if (upload_wall_textures(game) != 0)
		return (free_game(game), 1);
	init_player(game);
	game->rays = NULL;
	game->mouse_initialized = 0;
	game->prev_mouse_x = 0;
	game->enemy_left = game->enemy_count;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERR_USAGE), 1);
	if (get_map(&game, argv[1]) < 0)
		return (1);
	if (place_enemies(&game) < 0)
		return (free_parsing(&game), 1);
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
	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop_hook(game.mlx, draw_counter, &game);
	mlx_loop(game.mlx);
	return (0);
}
