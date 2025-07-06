#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define WIDTH 1000
# define HEIGHT 1000

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
	double			hit_x;
	double			hit_y;
	double			dist;
	bool			hit_vert;
	int				dir;
}	t_ray;

typedef struct s_enemy
{
	double		x;
	double		y;
	double		dist;
	int			frame;
	int			alive;
	double		dx;
	double		dy;
	double		angle_en;
	double		distance;
	int			sprite_size;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
}	t_enemy;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	t_player		*player;
	t_ray			*rays;
	mlx_image_t		*minimap_img;
	mlx_image_t		*counter_frame;
	mlx_image_t		*counter;
	mlx_image_t		*scene;
	mlx_image_t		*img[4];
	mlx_image_t		*weapon_image;
	mlx_image_t		*anim[6];
	double			ray_dists[WIDTH];
	int				enemy_count;
	int				enemy_left;
	int				frame_count;
	char			*unicorn_amount;
	t_enemy			*enemies;
	int				size_x;
	int				size_y;
	int				color_f;
	int				color_c;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				prev_mouse_x;
	int				mouse_initialized;
}	t_game;

#endif
