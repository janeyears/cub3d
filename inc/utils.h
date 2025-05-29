#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

// Parsing utils

int		file_check(char *fname);
bool	if_inside(char c);
int		skip_spaces(char *str);
void	free_arr(char **arr);
void	free_game(t_game *game);
void	free_parsing(t_game *game);
// Linked list utils

void	print_linked_list(t_list *lst);
t_list	*lstnew_m(void *content);
void	skip_new_line(t_list **map);
void	lst_del_first(t_list **lst);
char	**list_to_arr(t_list *list);

#endif