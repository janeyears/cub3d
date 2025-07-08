/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:03 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/08 15:31:12 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "cub3d.h"

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

# define WIDTH 1200
# define HEIGHT 1200

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

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

int		init_image(t_game *game);
void	close_hook(void *game);
void	esc_hook(mlx_key_data_t input, void *data);
int		upload_wall_textures(t_game *game);
void	init_player(t_game *game);
void	game_loop(void *param);
void	handle_movement(t_game *game);

t_ray	raycast(t_game *game, t_player *player, float angle);

void	render_scene(t_game *game);

#endif
