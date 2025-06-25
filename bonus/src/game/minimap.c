#include "cub3d.h"

static void	put_pixel_mini(t_game *game, t_mini mini)
{
	uint32_t	color;
	int			x;
	int			y;

	x = mini.center_x + mini.dx;
	y = mini.center_y + mini.dy;
	if (game->map[mini.tile_y][mini.tile_x] == '1')
		color = 0x444444FF;
	else if (if_inside(game->map[mini.tile_y][mini.tile_x]))
		color = 0xAAAAAAFF;
	else
		return ;
	mlx_put_pixel(game->minimap_img, x, y, color);
}

static void	mini_init(t_mini *mini)
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

void	clean_minimap(t_game *game)
{
	int		x = 0;
	int		y = 0;

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
			if (dx * dx + dy * dy <= 16 && x + dx >= 0 && x + dx < MINIMAP_SIZE &&
					y + dy >= 0 && y + dy < MINIMAP_SIZE)
				mlx_put_pixel(img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	put_enemy_minimap(t_game *game)
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
		if (mini.dx * mini.dx + mini.dy * mini.dy <= MINIMAP_RADIUS * MINIMAP_RADIUS)
			put_dot(game->minimap_img, mini.dx + MINIMAP_RADIUS, mini.dy + MINIMAP_RADIUS, 0xFF0000FF);
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
