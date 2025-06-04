// "Error\n" followed by an explicit error message of your choice.

# include "cub3d.h"

void err_msg(char *msg)
{
	char *red = "\033[1;31m";		// Bright red
	char *reset = "\033[0m";		// Reset color

	write(2, red, 7);				// Set text to red
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	write(2, reset, 4);			// Reset to normal color
}
