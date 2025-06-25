#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

#define MINIMAP_SCALE 10           // pixels per tile
#define MINIMAP_RADIUS 254         // radius in pixels
#define MINIMAP_SIZE (MINIMAP_RADIUS * 2)

void	draw_minimap(void *param);
void	draw_counter(void *param);

void	mini_init(t_mini *mini);
void	clean_minimap(t_game *game);
void	put_dot(mlx_image_t *img, int x, int y, uint32_t color);
void	put_pixel_mini(t_game *game, t_mini mini);

#endif