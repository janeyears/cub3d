#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "cub3d.h"

# define EAST_POV 0			    // pointing right
# define SOUTH_POV M_PI_2	    // pointing down (positive Y in screen coords)
# define WEST_POV M_PI		    // pointing left  
# define NORTH_POV 3*M_PI_2	    // pointing up (negative Y in screen coords)


# define FOV (M_PI / 3.0f)

# define TILE_SIZE 64
# define ROT_SPEED 2.5
//# define SPEED 5
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
	t_ray ray;        // already has hit_x, hit_y, dist, dir, hit_vert
	int wall_height;
	int wall_start;
	int wall_end;
	int tex_x;
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

t_ray	raycast(t_game *game, t_player *player, float angle);

void	render_scene(t_game *game);

#endif
