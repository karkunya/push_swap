#include "push_swap.h"


int srh_mid(t_list *list)
{
	int max;
	t_list *temp;
	temp = list->ptr;

	max = list->pos;
	while (temp != list)
	{
		if (max < temp->pos)
			max = temp->pos;
		temp = temp->ptr;
	}
	return (max);
}

void alg(t_list **a_list, t_list **b_list)
{
	t_list *ptrl;
	int mid;
	int cntr;

	ptrl = lst_ptr(*a_list);
	mid = srh_mid(*a_list);
	cntr = 0;
	while (cntr < mid)
	{
		if ((*a_list)->pos <= mid)
		{
			pb(a_list, b_list);
			cntr++;
		}
		else
			ra(a_list);
	}
}