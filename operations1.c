/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:13:57 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 19:13:59 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a_list)
{
	write(1, "ra\n", 3);
	*a_list = (*a_list)->ptr;
}

void	rb(t_list **list)
{
	write(1, "rb\n", 3);
	*list = (*list)->ptr;
}

void	rr(t_list **a_list, t_list **b_list)
{
	write(1, "rr\n", 3);
	ra(a_list);
	rb(b_list);
}

void	rra(t_list **a_list)
{
	write(1, "rra\n", 4);
	*a_list = lst_ptr(*a_list);
}

void	rrb(t_list **b_list)
{
	write(1, "rrb\n", 4);
	*b_list = lst_ptr(*b_list);
}
