#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

// Parsing utils

int		file_check(char *fname);

// Linked list utils

void	print_linked_list(t_map *lst);
int		lstadd(t_map **lst, char *content);
int		lstsize(t_map *lst);
void	skip_new_line(t_map **map);
void	lst_del_first(t_map **lst);

#endif