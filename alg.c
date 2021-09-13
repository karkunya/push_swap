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
	t_list *prnt;

	util.next = 1;
	util.flag = 2;
	ptrl = lst_ptr(*a_list);
	mid = (srh_max(*a_list) / 2 + util.next);
	cntr = 0;
	while (cntr + 1 < mid)
	{
//		if ((*a_list)->pos == util.next)
//		{
//			((*a_list)->flag = 1);
//			ra(a_list);
////			cntr++;
//			continue;
//		}
		if ((*a_list)->pos <= mid)
		{
			(*a_list)->flag++;
			pb(a_list, b_list);
			cntr++;
		}
		else
			ra(a_list);
	}
//	prnt = b_list;
//	printf("\n ");
//	printf("b_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
//	prnt = prnt->ptr;
//	while (prnt != b_list)
//	{
//		printf("b_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
//		prnt = prnt->ptr;
//	}
//	printf("\n ");
	while (*b_list != NULL) {
		mid = ((srh_max(*b_list) - util.next) / 2 + util.next);
		cntr = list_len(*b_list);
//		write(1, ".\n", 2);
		while ((*b_list != NULL) && cntr)
		{
			if ((*b_list)->pos == util.next)
			{
				(*b_list)->flag = 1;
				pa(a_list, b_list);
				ra(a_list);
				util.next++;
				cntr--;
				continue;
			}
			if ((*b_list)->pos > mid) {
				(*b_list)->flag = util.flag;
				pa(a_list, b_list);
			} else
				rb(b_list);
			cntr--;
		}
		util.flag++;
	}

}