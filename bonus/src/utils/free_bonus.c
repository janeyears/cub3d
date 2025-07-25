/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:13 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 15:12:32 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (game->color_c)
		free(game->color_c);
	if (game->color_f)
		free(game->color_f);
	if (game->map)
		free_arr(game->map);
}

void	free_game(t_game *game)
{
	free_parsing(game);
	if (game->enemies)
		free(game->enemies);
	if (game->unicorn_amount)
		free(game->unicorn_amount);
	mlx_terminate(game->mlx);
	exit(0);
}

void	free_texture(t_game *game)
{
	free_parsing(game);
	mlx_terminate(game->mlx);
	exit(0);
}

void	end_game(t_game *game)
{
	ft_putendl_fd("You saved the world from unicorns. Congratulations!", 1);
	free_game(game);
}
