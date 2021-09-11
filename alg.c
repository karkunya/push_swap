#include "push_swap.h"

int srh_max(t_list *list)
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
	t_util util;

	util.next = 1;
	ptrl = lst_ptr(*a_list);
	mid = (srh_max(*a_list) / 2 + util.next);
	cntr = 0;
	while (cntr + 1 < mid)
	{
		if ((*a_list)->pos < mid)
		{
			(*a_list)->flag++;
			pb(a_list, b_list);
			cntr++;
		}
		else
			ra(a_list);
	}
	mid = ((srh_max(*b_list) - util.next) / 2 + util.next);
	cntr = 0;
	while (cntr < mid)
	{
		if ((*b_list)->pos == util.next)
		{
			pa(a_list, b_list);
			ra(a_list);
			util.next++;
			cntr++;
			continue;
			write(1, ".\n", 2);
		}
		if ((*b_list)->pos <= mid)
		{
			(*b_list)->flag++;
			pa(a_list, b_list);
			cntr++;
		}
		else
			rb(b_list);
	}
}