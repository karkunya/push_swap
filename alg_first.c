#include "push_swap.h"

void alg(t_list **a_list, t_list **b_list)
{
	//	t_list *temp;
	int i = 10;

	pb(a_list, b_list);
	pb(a_list, b_list);
	if ((*b_list)->num < ((*b_list)->ptr)->num) {
		rb(b_list);
	}
	while (*a_list)
	{
		while (((*a_list)->pos > (*b_list)->pos) && i-- > 0) {
			rb(b_list);
		}
		i = 10;
		pb(a_list, b_list);
//		printf("1while work\n");
	}
	pb(b_list, a_list);
	pb(b_list, a_list);
	if ((*a_list)->num < ((*a_list)->ptr)->num)
		ra(a_list);
	while (*b_list)
	{
		write(1, ".\n", 2);
		while (((*b_list)->pos > (*a_list)->pos) && i-- > 0)
			ra(a_list);
		i = 10;
		pa(a_list, b_list);
	}
}