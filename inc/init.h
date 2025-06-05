#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define WIDTH 1200
# define HEIGHT 1200

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_player
{
	double		x;
	double		y;
	char		pov;
	double		angle;
}	t_player;

typedef struct s_ray
{
	// float		ang;			// curr RAY aNGLE 
	double		hit_x;			//hip point by x
	double		hit_y;			// hit point by y
	double		dist;			// dist to wall
	bool		hit_vert;		// hit vertical - 1, hit horizontal - 0
	int			dir;
}	t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	t_player	*player;
	t_ray		*rays;		// array of rays
	mlx_image_t		*background;
	mlx_image_t		*minimap_img; // minimap
	mlx_image_t		*scene;		// image for rendering
	mlx_texture_t	*texture[4];
	int			size_x; 	// max number of columns
	int			size_y; 	// number of rows
	int			*ceiling;	// int array [red, green, blue] // need remove
	int			*floor;		// int array [red, green, blue] // need remoove
	int			color_f;
	int			color_c;
	char*		no_path;
	char*		so_path;
	char*		we_path;
	char*		ea_path;
}	t_game;

#endif
