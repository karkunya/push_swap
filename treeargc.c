/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeargc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:04:18 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/12 20:26:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_4_numbers(t_list **a, t_list **b)
{
	while (list_len(*a) > 3)
	{
		if ((*a)->pos == 1)
			pb(a, b);
		else
			ra(a);
	}
	if (!is_list_sorted2(a))
		sort_3_numbers(a);
	if ((*b)->num < (*b)->ptr->num)
		rb(b);
	pa(a, b);
}

void	sort_5_numbers(t_list **a, t_list **b)
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
