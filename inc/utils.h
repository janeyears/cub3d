#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"


// Linked list utils

void	print_linked_list(t_map *lst);
int		lstadd(t_map **lst, char *content);
int		lstsize(t_map *lst);

#endif