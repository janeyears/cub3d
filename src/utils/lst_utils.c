# include "cub3d.h"

void	print_linked_list(t_map *lst)
{
	t_map	*current;

	current = lst;
	printf("\033[1;93mThis is your MAP\n\n");
	while (current)
	{
		printf("%s",current->content);
		current = current->next;
	}
	printf("\033\n");
}

int	lstadd(t_map **lst, char *content)
{
	t_map	*tmp;
	t_map	*new;

	if (!content)
		return (1);
	new = ft_calloc(1, sizeof(*new));
	if (!new)
		return (-1);
	new->content = ft_strdup(content);
	if (!new->content)
		return (-1);
	new->next = NULL;
	if (lst && new)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next; // LAST FROM LIST
			tmp->next = new;
			tmp->next->size_x = ft_strlen(content);
		}
		else
		{
			*lst = new;
			(*lst)->size_x = ft_strlen(content);
		}
	}
	return (1);
}

int	lstsize(t_map *lst)
{
	size_t	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
