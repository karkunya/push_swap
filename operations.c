#include "push_swap.h"

t_list *lst_ptr(*list)
{
	t_list	*temp;

	temp = *list;
//	(*ptr)->num = ((*ptr)->ptr)->ptr;
	while (temp != list->ptr)
		list = list->ptr;
	return (list)
}

void	sa(t_list **ptr)
{
	int	temp;

	temp = (*ptr)->num;
	(*ptr)->num = ((*ptr)->ptr)->num;
	((*ptr)->ptr)->num = temp;
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(**list_a);
	sa(**list_b);
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list *ptrl;

	


}
