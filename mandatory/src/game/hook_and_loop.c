/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:42 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/08 15:30:56 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_hook(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	free_game(game);
}

void	esc_hook(mlx_key_data_t input, void *data)
{
	t_game	*game;

	(void)input;
	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		free_game(game);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_movement(game);
	render_scene(game);
}
