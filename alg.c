#include "push_swap.h"

void	from_b_to_a_cycle(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list	*b_first;

	b_first = *b_list;
	if (b_first->pos == util->next)
	{
		util->next++;
		b_first->flag = util->flag;
		pa(a_list, b_list);
		ra(a_list);
		return ;
	}
	else if (b_first->pos >= util->mid)
	{
		b_first->flag = util->flag;
		pa(a_list, b_list);
	}
}

void	from_b_to_a(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list	*b_first;
	t_list	*b_last;

	b_first = *b_list;
	if (!b_first)
		return ;
	b_last = lst_ptr(b_first);
	util->mid = (((util->mid - util->next) / 2) + util->next);
	util->flag++;
	while (b_first != b_last)
	{
		b_first = *b_list;
		if (!(b_first->pos == util->next || b_first->pos >= util->mid))
			rb(b_list);
		else
			from_b_to_a_cycle(a_list, b_list, util);
	}
	if (*b_list)
		from_b_to_a_cycle(a_list, b_list, util);
}

void	from_a_to_b_cycle(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list	*a_first;
	int		flag;

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

void	from_a_to_b(t_list **a_list, t_list **b_list, t_util *util)
{
	t_list	*a_first;
	t_list	*a_last;
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

void	alg(t_list **a_list, t_list **b_list)
{
	t_util	util;

	init_util(&util);
	util.mid = (srh_max(*a_list, &util) / 2 + util.next);
	first_iteration(a_list, b_list, &util);
	while (!is_list_sorted(a_list, b_list))
	{
		if (*b_list)
			util.mid = srh_max(*b_list, &util);
		while (*b_list)
		{
			from_b_to_a(a_list, b_list, &util);
		}
		if (!is_list_sorted2(a_list))
			from_a_to_b(a_list, b_list, &util);
	}
	free_list(a_list);
}
