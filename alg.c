#include "push_swap.h"

int	is_list_sorted(t_list **a, t_list **b)
{
	t_list	*temp;
//	write(1, "1.\n", 3);
	temp = *b;
	if (temp)
		return (0);
	temp = *a;
	while (temp->ptr != *a)
	{
//		write(1, "2.\n", 3);
		if (temp->ptr->pos < temp->pos)
			return(0);
		temp = temp->ptr;
	}
//	if (temp->ptr->pos < temp->pos)
//		return(0);
//	temp = temp->ptr;
	return (1);
}

int srh_max(t_list *list, t_util *util)
{
	int flag;
	int max;

	flag = list->flag;
	t_list *temp;
	temp = list->ptr;


	max = list->pos;
	while ((temp != list) && (temp->flag == flag))
	{
		if (max < temp->pos)
			max = temp->pos;
		temp = temp->ptr;
//		printf(".\n");
	}
	return (max);
}


void from_b_to_a(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list *temp;

	while (*b_list != NULL)
	{
		temp = *b_list;
		(*util).mid = ((srh_max(*b_list, util) - (*util).next) / 2 + (*util).next);
		(*util).cntr = list_len(*b_list);
//		while ((*b_list != NULL) && (*util).cntr)
		while ((*b_list && (*temp).ptr != *b_list))
		{
			if ((*b_list)->pos == (*util).next)
			{
				(*b_list)->flag = 1;
				pa(a_list, b_list);
				ra(a_list);
				(*util).next++;
//				(*util).cntr--;
				continue;
			}
			if ((*b_list)->pos >= (*util).mid) {
				(*b_list)->flag = (*util).flag;
				pa(a_list, b_list);
			} else
				rb(b_list);
			(*util).cntr--;
		}
		(*util).flag++;
	}
}

void first_iteration(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list *ptrl;
	t_list *prnt;

	ptrl = lst_ptr(*a_list);
	while (util->cntr < util->mid)
	{
//		if ((*a_list)->pos == util.next)
//		{
//			((*a_list)->flag = 1);
//			ra(a_list);
////			cntr++;
//			continue;
//		}
		if ((*a_list)->pos <= util->mid)
		{
			(*a_list)->flag++;
			pb(a_list, b_list);
			util->cntr++;
		}
		else
			ra(a_list);
	}
	if ((*a_list)->pos <= util->mid)
		pb(a_list, b_list);
}

void init_util(t_util *util)
{
	util->next = 1;
	util->flag = 2;
	util->cntr = 0;

}

int is_list_sorted2(t_list **a_list)
{
	t_list *temp;

	temp = *a_list;
	while (temp->ptr != *a_list)
	{
		if (temp->ptr->pos < temp->pos)
			return(0);
		temp = temp->ptr;
	}
//	if (temp->ptr->pos < temp->pos)
//		return(0);
//	temp = temp->ptr;
	return (1);
}


void	from_a_to_b_cycle(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list *a_first;
	int flag;

	a_first = *a_list;
	flag = a_first->flag;
	if (a_first->pos == util->next)
	{
		util->next++;
		ra(a_list);
	}
	else if (a_first->flag == flag)
		pb(a_list, b_list);
}

void from_a_to_b(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list *a_first;
	t_list *a_last;
	int		flag;

	a_first = *a_list;
	a_last = lst_ptr(a_first);
	flag = a_first->flag;
	while (a_first != a_last)
	{
		a_first = *a_list;
		if (a_first->flag != flag)
			return ;
		from_a_to_b_cycle(a_list, b_list, util);
	}
	from_a_to_b_cycle(a_list, b_list, util);
}


void alg(t_list **a_list, t_list **b_list)
{
	int i = 8;
	t_util util;
	init_util(&util);
	util.mid = (srh_max(*a_list, &util) / 2 + util.next);
	first_iteration(a_list, b_list, &util);
	while (!is_list_sorted(a_list, b_list))
	{
//		write(1, "3.\n", 3);
		util.mid = srh_max(*b_list, &util);
		while (*b_list)
			from_b_to_a(a_list, b_list, &util);
		if (!is_list_sorted2(a_list))
			from_a_to_b(a_list, b_list, &util);
	}
}