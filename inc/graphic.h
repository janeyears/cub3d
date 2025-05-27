#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "cub3d.h"

# define EAST_POV 0		// 0 degrees in radians		
# define NORTH_POV M_PI + M_PI_2	// 90 degrees in radians
# define WEST_POV M_PI		// 180 degrees in radians
# define SOUTH_POV M_PI_2	// 270 degrees in radians

# define TILE_SIZE 64
# define ROT_SPEED 2.5

void	render_f_and_c(t_game *game);
void	get_color_code(t_game *game);
int		rerender_image(t_game *game);
void	key_hook(mlx_key_data_t input, void *game);
int		upload_wall_textures(t_game *game);
void	init_player(t_game *game);

void	rotate_player(t_game *game, int direction);

#endif
