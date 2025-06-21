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
		color = 0x00000000;
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

void	draw_minimap(void *param)
{
	int		center_x;
	int		center_y;
	int		dy;
	int		dx;
	t_game	*game;

	center_x = MINIMAP_RADIUS;
	center_y = MINIMAP_RADIUS;
	game = (t_game *)param;
	clean_minimap(game);
	put_minimap(game);
	dy = -4;
	while (dy <= 4)
	{
		dx = -4;
		while (dx <= 4)
		{
			if (dx * dx + dy * dy <= 16)
				mlx_put_pixel(game->minimap_img, center_x + dx,
					center_y + dy, 0x00FF00FF);
			dx++;
		}
		dy++;
	}
}
