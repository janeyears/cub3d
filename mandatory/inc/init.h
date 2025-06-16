#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_player
{
	double			x;
	double			y;
	char			pov;
	double			angle;
}	t_player;

typedef struct s_ray
{
	double			hit_x;			//hip point by x
	double			hit_y;			// hit point by y
	double			dist;			// dist to wall
	bool			hit_vert;		// hit vertical - 1, hit horizontal - 0
	int				dir;			// N S E W for textures
}	t_ray;

typedef struct	s_game
{
	mlx_t			*mlx;
	char			**map;
	t_player		*player;
	t_ray			*rays;				// array of rays
	mlx_image_t		*minimap_img;	// minimap
	mlx_image_t		*scene;			// image for rendering
	mlx_image_t		*img[4];
	int				size_x; 			// max number of columns
	int				size_y; 			// number of rows
	int				color_f;
	int				color_c;
	char*			no_path;
	char*			so_path;
	char*			we_path;
	char*			ea_path;
	int				prev_mouse_x;
	int				mouse_initialized;		// sprite for animation
}	t_game;

#endif
