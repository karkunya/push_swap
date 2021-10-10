/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:14:27 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 19:14:29 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_iteration(t_list **a_list, t_list **b_list, t_util *util)
{
	while (util->cntr < util->mid)
	{
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

void	init_util(t_util *util)
{
	util->next = 1;
	util->flag = 2;
	util->cntr = 0;
}

int	srh_max(t_list *list, t_util *util)
{
	int		flag;
	int		max;
	t_list	*temp;
	t_list	*list_lst;

	flag = list->flag;
	list_lst = lst_ptr(list);
	temp = list;
	max = list->pos;
	while ((temp != list_lst) && (temp->flag == flag))
	{
		if (max < temp->pos)
			max = temp->pos;
		temp = temp->ptr;
	}
	if ((temp->flag == flag) && (max < temp->pos))
		max = temp->pos;
	return (max);
}

int	is_list_sorted(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (temp)
		return (0);
	temp = *a;
	while (temp->ptr != *a)
	{
		if (temp->ptr->pos < temp->pos)
			return (0);
		temp = temp->ptr;
	}
	return (1);
}

int	is_list_sorted2(t_list **a_list)
{
	t_list	*temp;

	temp = *a_list;
	while (temp->ptr != *a_list)
	{
		if (temp->ptr->pos < temp->pos)
			return (0);
		temp = temp->ptr;
	}
	return (1);
}
