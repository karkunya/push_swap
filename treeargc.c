#include "push_swap.h"

void	sort_3_numbers(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if (temp->num < temp->ptr->num && temp->num < temp->ptr->ptr->num)
		sa(a), ra(a);
	else if (temp->num > temp->ptr->num && temp->num > temp->ptr->ptr->num)
	{
		if (temp->ptr->num < temp->ptr->ptr->num)
			ra(a);
		else
			sa(a), rra(a);
	}
	else
	{
		if (temp->ptr->num < temp->ptr->ptr->num)
			sa(a);
		else
			rra(a);
	}
}

void	sort_4_numbers_additional_func(t_list **a, t_list **b)
{
	t_list	*a_temp;
	t_list	*b_temp;

	a_temp = *a;
	b_temp = *b;
	if (a_temp->num > b_temp->num)
		pa(a, b);
	else if (a_temp->num < b_temp->num && a_temp->ptr->num > b_temp->num)
		pa(a, b), sa(a);
	else if (a_temp->ptr->num < b_temp->num && \
			a_temp->ptr->ptr->num > b_temp->num)
		ra(a), pa(a, b), sa(a), rra(a);
	else if (a_temp->ptr->ptr->num < b_temp->num)
		pa(a, b), ra(a);
}

void	sort_4_numbers(t_list **a, t_list **b)
{
	pb(a, b);
	sort_3_numbers(a);
	sort_4_numbers_additional_func(a, b);
}

void sort_5_numbers(t_list **a, t_list **b)
{
	while (list_len(*a) > 3)
	{
		if ((*a)->pos == 1 || (*a)->pos == 2)
			pb(a, b);
		else
			ra(a);
	}
	if (!is_list_sorted2(a))
		sort_3_numbers(a);
	if ((*b)->num < (*b)->ptr->num)
		rb(b);
	pa(a, b);
	pa(a, b);
}
