/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:46 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:47 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_pixel_mini(t_game *game, t_mini mini)
{
	uint32_t	color;
	int			x;
	int			y;

	x = mini.center_x + mini.dx;
	y = mini.center_y + mini.dy;
	color = 0xAAAAAA00;
	if (mini.tile_y < game->size_x && mini.tile_x
		< (int)ft_strlen(game->map[mini.tile_y]))
	{
		if (game->map[mini.tile_y][mini.tile_x] == '1')
			color = 0x444444FF;
		else if (if_inside(game->map[mini.tile_y][mini.tile_x]))
			color = 0xAAAAAAFF;
		else
			return ;
	}
	mlx_put_pixel(game->minimap_img, x, y, color);
}

void	mini_init(t_mini *mini)
{
	mini->center_x = MINIMAP_RADIUS;
	mini->center_y = MINIMAP_RADIUS;
	mini->dy = -MINIMAP_RADIUS;
	mini->dx = 0;
	mini->map_x = 0;
	mini->map_y = 0;
	mini->tile_x = 0;
	mini->tile_y = 0;
	mini->rdy = 0;
	mini->rdx = 0;
	mini->tile_x = 0;
	mini->tile_y = 0;
}

void	clean_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	put_dot(mlx_image_t *img, int x, int y, uint32_t color)
{
	int		dx;
	int		dy;

	dy = -4;
	while (dy <= 4)
	{
		dx = -4;
		while (dx <= 4)
		{
			if (dx * dx + dy * dy <= 16 && x + dx >= 0 && x + dx < MINIMAP_SIZE
				&& y + dy >= 0 && y + dy < MINIMAP_SIZE)
				mlx_put_pixel(img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}
