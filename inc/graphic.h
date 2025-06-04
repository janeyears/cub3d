#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "cub3d.h"

# define EAST_POV 0		    // pointing right
# define SOUTH_POV M_PI_2	    // pointing down (positive Y in screen coords)
# define WEST_POV M_PI		    // pointing left  
# define NORTH_POV 3*M_PI_2	    // pointing up (negative Y in screen coords)


# define FOV (M_PI / 3.0f) 

# define TILE_SIZE 64
# define ROT_SPEED 2.5
# define SPEED 5

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

void	render_f_and_c(t_game *game);
void	get_color_code(t_game *game);
int		init_image(t_game *game);
void	close_hook(void *game);
void	esc_hook(mlx_key_data_t input, void *data);
int		upload_wall_textures(t_game *game);
void	init_player(t_game *game);
void	game_loop(void *param);
void	handle_movement(t_game *game);

//void	raycasting(t_game *game);
t_ray raycast(t_game *game, t_player *player, float angle);

void	render_scene(t_game *game);

#endif
