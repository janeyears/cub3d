#include "cub3d.h"

static void	get_tile(t_game *game, t_mini *mini)
{
	float	rotation_angle;

	rotation_angle = -game->player->angle + NORTH_POV;
	mini->rdx = mini->dx * cosf(-rotation_angle)
		- mini->dy * sinf(-rotation_angle);
	mini->rdy = mini->dx * sinf(-rotation_angle)
		+ mini->dy * cosf(-rotation_angle);
	mini->map_x = game->player->x / TILE_SIZE
		+ mini->rdx / (float)MINIMAP_SCALE;
	mini->map_y = game->player->y / TILE_SIZE
		+ mini->rdy / (float)MINIMAP_SCALE;
	if (mini->map_x >= 0)
		mini->tile_x = (int)mini->map_x;
	else
		mini->tile_x = (int)floorf(mini->map_x);
	if (mini->map_y >= 0)
		mini->tile_y = (int)mini->map_y;
	else
		mini->tile_y = (int)floorf(mini->map_y);
}

static void	put_minimap(t_game *game)
{
	t_mini		mini;

	mini_init(&mini);
	while (mini.dy < MINIMAP_RADIUS)
	{
		mini.dx = -MINIMAP_RADIUS;
		while (mini.dx < MINIMAP_RADIUS)
		{
			if (mini.dx * mini.dx + mini.dy * mini.dy
				> MINIMAP_RADIUS * MINIMAP_RADIUS)
			{
				mini.dx++;
				continue ;
			}
			get_tile(game, &mini);
			if (mini.tile_y >= 0 && mini.tile_y < game->size_y
				&& mini.tile_x >= 0 && mini.tile_x < game->size_x)
			{
				put_pixel_mini(game, mini);
			}
			mini.dx++;
		}
		mini.dy++;
	}
}

static void	put_enemy_minimap(t_game *game)
{
	t_mini	mini;
	float	angle;
	int		i;

	i = -1;
	mini_init(&mini);
	while (++i < game->enemy_count)
	{
		if (!game->enemies[i].alive)
			continue;
		mini.map_x = game->enemies[i].x - game->player->x;
		mini.map_y = game->enemies[i].y - game->player->y;
		angle = -game->player->angle + NORTH_POV;
		mini.rdx = mini.map_x * cosf(angle) - mini.map_y * sinf(angle);
		mini.rdy = mini.map_x * sinf(angle) + mini.map_y * cosf(angle);
		mini.dx = (int)(mini.rdx * MINIMAP_SCALE / TILE_SIZE);
		mini.dy = (int)(mini.rdy * MINIMAP_SCALE / TILE_SIZE);
		if (mini.dx * mini.dx + mini.dy * mini.dy <= MINIMAP_RADIUS
				* MINIMAP_RADIUS)
			put_dot(game->minimap_img, mini.dx + MINIMAP_RADIUS,
				mini.dy + MINIMAP_RADIUS, 0xFF0000FF);
	}
}

void	draw_minimap(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_minimap(game);
	put_minimap(game);
	put_dot(game->minimap_img, MINIMAP_RADIUS, MINIMAP_RADIUS, 0x00FF00FF);
	put_enemy_minimap(game);
}

void	draw_counter(void *param)
{
	t_game		*game;
	char		*count;
	static int	old_count;

	game = (t_game *)param;
	old_count = -1;
	if (old_count != game->enemy_left)
	{
		if (game->counter)
			mlx_delete_image(game->mlx, game->counter);

		count = ft_itoa(game->enemy_left);
		if (!count)
			free_game(game);
		game->counter = mlx_put_string(game->mlx, count, WIDTH - 95, 30);
		free(count);
		old_count = game->enemy_left;
	}
}


