#include "push_swap.h"

t_list *lst_ptr(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != list->ptr)
		list = list->ptr;
	return (list);
}

int 	list_len(t_list *list)
{
	t_list *temp;
	int i;


	if (!(list))
		return (0);
	i = 1;
	temp = list;
	while (temp != list->ptr && i++)
		list = list->ptr;
	return (i);
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
	sa(list_a);
	sa(list_b);
}

void 	pb_low(t_list **list_a, t_list **list_b)
{
	t_list *ptrl;
	t_list *temp;

	temp = *list_a;
	ptrl = lst_ptr(*list_b);
	temp->ptr = *list_b;
	*list_b = temp;
	ptrl->ptr = *list_b;
	*list_a = NULL;
}


// dsnt work with 1 or 2 nums
void	pb(t_list **list_a, t_list **list_b)
{
	t_list *ptrl;
	t_list *temp;
//	printf("\n ******%d *** \n", list_len(*list_a));
	if (*list_a)
    {
		if (list_len(*list_a) == 1)
		{
			pb_low(list_a, list_b);
			return ;
		}
		if (!(*list_b))
        {
			*list_b = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			(*list_b)->ptr = *list_b;
		}
        else
        {
			temp = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			ptrl = lst_ptr(*list_b);
			temp->ptr = *list_b;
			*list_b = temp;
			ptrl->ptr = *list_b;
		}
//		if (list_len(*list_a) == 2)
//		{
//			(*list_a)->ptr = *list_a;
//			printf("\n==2\n");
//		}
//		if (list_len(*list_a) == 1)
//			*list_a = NULL;
	}
}

void	pa(t_list **list_b, t_list **list_a)
{
	t_list *ptrl;
	t_list *temp;

	if (*list_a)
	{
		if (list_len(*list_a) == 1)
		{
			pb_low(list_a, list_b);
			return ;
		}
		if (!(*list_b))
		{
			*list_b = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			(*list_b)->ptr = *list_b;
		}
		else
		{
			temp = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			ptrl = lst_ptr(*list_b);
			temp->ptr = *list_b;
			*list_b = temp;
			ptrl->ptr = *list_b;
		}
	}
}

void    ra(t_list **a_list)
{
    *a_list = (*a_list)->ptr;
}

void    rb(t_list **list)
{
    *list = (*list)->ptr;
}

void    rr(t_list **a_list, t_list **b_list)
{
    ra(a_list);
    rb(b_list);
}

void    rra(t_list **a_list)
{
    *a_list = lst_ptr(*a_list);
}

void    rrb(t_list **b_list)
{
    *b_list = lst_ptr(*b_list);
}

void    rrr(t_list **a_list, t_list **b_list)
{
    rra(a_list);
    rrb(b_list);
}
