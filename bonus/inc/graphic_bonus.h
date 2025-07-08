/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:14:45 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/08 14:19:27 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_BONUS_H
# define GRAPHIC_BONUS_H

# include "cub3d_bonus.h"

# define EAST_POV 0
# define SOUTH_POV M_PI_2
# define WEST_POV M_PI
# define NORTH_POV 4.71238898038f

# define FOV 1.04719755120f

# define TILE_SIZE 64
# define ROT_SPEED 2.5
# define TEX_SIZE 1076
# define MIN_DISTANCE 0.1f
# define MOUSE_SENSITIVITY 0.003

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define FRAME_DELAY 10
# define PATH_E1 "./textures/1-1.png"
# define PATH_E2 "./textures/2-1.png"
# define PATH_E3 "./textures/3-1.png"
# define PATH_E4 "./textures/4-1.png"
# define PATH_E5 "./textures/3-1.png"
# define PATH_E6 "./textures/2-1.png"
# define PATH_COUNT "./textures/counter.png"

typedef struct s_cast
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		map_x;
	int		map_y;
}	t_cast;

typedef struct s_column
{
	t_ray	ray;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		tex_x;
}	t_column;

typedef struct s_mini
{
	int		center_x;
	int		center_y;
	int		dy;
	int		dx;
	float	map_x;
	float	map_y;
	int		tile_x;
	int		tile_y;
	float	rdx;
	float	rdy;
}	t_mini;

int		init_image(t_game *game);
void	close_hook(void *game);
void	esc_hook(mlx_key_data_t input, void *data);
int		upload_wall_textures(t_game *game);
void	init_player(t_game *game);
void	game_loop(void *param);
void	handle_movement(t_game *game);
void	handle_mouse_rotation(t_game *game);

void	norm_angle_en(t_game *game, int i);
void	update_enemy_animation(t_game *game);
int		place_enemies(t_game *game);
void	enemy_dist(t_game *game);
int		get_enemy_coords(t_game *game);
void	sort_enemies(t_game *game);
void	render_enemies(t_game *game);
void	check_enemy_collision(t_game *game, double new_x, double new_y);

t_ray	raycast(t_game *game, t_player *player, float angle);
void	render_scene(t_game *game);

#endif
