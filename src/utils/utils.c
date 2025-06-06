#include "cub3d.h"

int	file_check(char *fname)
{
	return (!ft_strchr(fname, '.')
		|| ft_strncmp((ft_strrchr(fname, '.')), ".cub\0", 5));
}

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int get_pixel_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t offset = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;

	uint8_t r = texture->pixels[offset + 0];
	uint8_t g = texture->pixels[offset + 1];
	uint8_t b = texture->pixels[offset + 2];
	uint8_t a = texture->pixels[offset + 3];

	// Combine RGBA into a single 32-bit color (MLX42 uses 0xRRGGBBAA format by default)
	return (r << 24) | (g << 16) | (b << 8) | a;
}