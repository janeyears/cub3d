
#include "cub3d.h"

void	print_linked_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	printf("\033[1;93m");
	while (current)
	{
		printf("%s",(char *)current->content);
		current = current->next;
	}
	printf("\n\033[0m");
}

t_list	*lstnew_m(void *content)
{
	t_list	*new;

	if (!content)
		return (NULL);
	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}

void	lst_del_first(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	if (!(*lst)->next)
	{
		ft_lstclear(lst, free);
		return ;
	}
	temp = *lst;
	*lst = temp->next;
	ft_lstdelone(temp, free);
}

void	skip_new_line(t_list **map)
{
	if (!map)
		return ;
	if ((*map)->content && ((char *)(*map)->content)[0] == '\n')
		while (((char *)(*map)->content)[0] == '\n')
			lst_del_first(map);
}

char	**list_to_arr(t_list *list)
{
	char	**arr;
	int		i;
	t_list	*current;
	int		size;

	i = 0;
	current = list;
	size = ft_lstsize(list);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (current)
	{
		if (!current->content)
			return (NULL);
		if (i < size - 1)
			arr[i] = ft_substr(current->content, 0, ft_strlen(current->content) - 1);
		else
			arr[i] = ft_strdup(current->content);
		if (!arr[i++])
			return (NULL);
		current = current->next;
	}
	arr[i] = NULL;
	return (arr);
}
