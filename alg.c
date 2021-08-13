#include "push_swap.h"

//надо дописать ра рь
void alg(t_list **a_list, t_list **b_list)
{
	//	t_list *temp;
	int i = 10;

	pb(a_list, b_list);
	pb(a_list, b_list);
	if ((*b_list)->num < ((*b_list)->ptr)->num)
		rb(b_list);
	while (*a_list)
	{
		while (((*a_list)->pos < (*b_list)->pos) && i-- > 0)
			 rb(b_list);
		i = 10;
		pb(a_list, b_list);
	}
	while (*b_list)
		pa(a_list, b_list);
}