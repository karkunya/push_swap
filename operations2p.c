/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:03:04 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/11 19:06:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_low(t_list **list_a, t_list **list_b)
{
	t_list	*ptrl;
	t_list	*temp;

	if (list_len(*list_a) == 1)
	{
		temp = *list_a;
		ptrl = lst_ptr(*list_b);
		temp->ptr = *list_b;
		*list_b = temp;
		ptrl->ptr = *list_b;
		*list_a = NULL;
	}
	if (list_len(*list_a) == 2)
	{
		temp = *list_a;
		*list_a = (*list_a)->ptr;
		(*list_a)->ptr = *list_a;
		ptrl = lst_ptr(*list_b);
		temp->ptr = *list_b;
		*list_b = temp;
		ptrl->ptr = *list_b;
	}
}

void	pb_pa_dop(t_list **list_a, t_list **list_b, t_list *ptrl, t_list *temp)
{
	temp = *list_a;
	ptrl = lst_ptr(*list_a);
	*list_a = (*list_a)->ptr;
	ptrl->ptr = *list_a;
	ptrl = lst_ptr(*list_b);
	temp->ptr = *list_b;
	*list_b = temp;
	ptrl->ptr = *list_b;
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*ptrl;
	t_list	*temp;

	ptrl = NULL;
	temp = NULL;
	write(1, "pb\n", 3);
	if (*list_a)
	{
		if (list_len(*list_a) < 3)
		{
			pb_low(list_a, list_b);
			return ;
		}
		if (!(*list_b))
		{
			*list_b = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			(*list_b)->ptr = *list_b;
		}
		else
			pb_pa_dop(list_a, list_b, ptrl, temp);
	}
}

void	pa(t_list **list_b, t_list **list_a)
{
	t_list	*ptrl;
	t_list	*temp;

	ptrl = NULL;
	temp = NULL;
	write(1, "pa\n", 3);
	if (*list_a)
	{
		if (list_len(*list_a) == 1)
		{
			pb_low(list_a, list_b);
			return ;
		}
		if (!(*list_b))
		{
			*list_b = *list_a;
			ptrl = lst_ptr(*list_a);
			*list_a = (*list_a)->ptr;
			ptrl->ptr = *list_a;
			(*list_b)->ptr = *list_b;
		}
		else
			pb_pa_dop(list_a, list_b, ptrl, temp);
	}
}
