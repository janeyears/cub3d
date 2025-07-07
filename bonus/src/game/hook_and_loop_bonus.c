/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:35 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:36 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	handle_mouse_rotation(game);
	render_scene(game);
}
