#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

#define MINIMAP_SCALE 10           // pixels per tile
#define MINIMAP_RADIUS 254         // radius in pixels
#define MINIMAP_SIZE (MINIMAP_RADIUS * 2)

void	draw_minimap(void *param);

#endif