/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:54 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:17:55 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	vert_init(t_player *player, float angle, t_cast *cast, t_ray *ray)
{
	ray->dist = 1000000;
	ray->hit_vert = true;
	if (cos(angle) > 0)
		cast->x_step = TILE_SIZE;
	else
		cast->x_step = -TILE_SIZE;
	cast->y_step = cast->x_step * tan(angle);
	cast->x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (cos(angle) > 0)
		cast->x += TILE_SIZE;
	cast->y = player->y + (cast->x - player->x) * tan(angle);
}

t_ray	vertical_intersection(t_game *game, t_player *player, float angle)
{
	t_cast	cast;
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	vert_init(player, angle, &cast, &ray);
	while (1)
	{
		cast.map_x = (int)(cast.x / TILE_SIZE);
		if (cos(angle) < 0)
			cast.map_x--;
		cast.map_y = (int)(cast.y / TILE_SIZE);
		if (cast.map_y < 0 || cast.map_y >= game->size_y || cast.map_x < 0
			|| cast.map_x >= (int)ft_strlen(game->map[cast.map_y]))
			break ;
		if (game->map[cast.map_y][cast.map_x] == '1')
		{
			ray.hit_x = cast.x;
			ray.hit_y = cast.y;
			ray.dist = hypot(cast.x - player->x, cast.y - player->y);
			return (ray);
		}
		cast.x += cast.x_step;
		cast.y += cast.y_step;
	}
	return (ray);
}

static void	hor_init(t_player *player, float angle, t_cast *cast, t_ray *ray)
{
	ray->dist = 1000000;
	ray->hit_vert = false;
	if (sin(angle) > 0)
		cast->y_step = TILE_SIZE;
	else
		cast->y_step = -TILE_SIZE;
	cast->x_step = cast->y_step / tan(angle);
	cast->y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (sin(angle) > 0)
		cast->y += TILE_SIZE;
	cast->x = player->x + (cast->y - player->y) / tan(angle);
}

t_ray	horizontal_intersection(t_game *game, t_player *player, float angle)
{
	t_cast	cast;
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	hor_init(player, angle, &cast, &ray);
	while (1)
	{
		cast.map_y = (int)(cast.y / TILE_SIZE);
		if (sin(angle) < 0)
			cast.map_y--;
		cast.map_x = (int)(cast.x / TILE_SIZE);
		if (cast.map_y < 0 || cast.map_y >= game->size_y || cast.map_x < 0
			|| cast.map_x >= (int)ft_strlen(game->map[cast.map_y]))
			break ;
		if (game->map[cast.map_y][cast.map_x] == '1')
		{
			ray.hit_x = cast.x;
			ray.hit_y = cast.y;
			ray.dist = hypot(cast.x - player->x, cast.y - player->y);
			return (ray);
		}
		cast.x += cast.x_step;
		cast.y += cast.y_step;
	}
	return (ray);
}

t_ray	raycast(t_game *game, t_player *player, float angle)
{
	t_ray	horz;
	t_ray	vert;

	horz = horizontal_intersection(game, player, angle);
	vert = vertical_intersection(game, player, angle);
	if (horz.dist < vert.dist)
	{
		if (sin(angle) > 0)
			horz.dir = 1;
		else
			horz.dir = 0;
		return (horz);
	}
	if (cos(angle) < 0)
		vert.dir = 2;
	else
		vert.dir = 3;
	return (vert);
}
