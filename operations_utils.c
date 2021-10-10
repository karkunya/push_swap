#include "push_swap.h"

t_list	*lst_ptr(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != list->ptr)
		list = list->ptr;
	return (list);
}

int	list_len(t_list *list)
{
	t_list	*temp;
	int		i;

	if (!(list))
		return (0);
	i = 1;
	temp = list;
	while (temp != list->ptr && i++)
		list = list->ptr;
	return (i);
}
