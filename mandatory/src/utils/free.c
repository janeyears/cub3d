/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 14:51:23 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (game->color_c)
		free(game->color_c);
	if (game->color_f)
		free(game->color_f);
	if (game->map)
		free_arr(game->map);
}

void	free_game(t_game *game)
{
	mlx_terminate(game->mlx);
	free_parsing(game);
	exit(0);
}
