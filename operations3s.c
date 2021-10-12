/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:14:15 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 19:14:17 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **ptr)
{
	int	temp;

	write(1, "sa\n", 3);
	temp = (*ptr)->num;
	(*ptr)->num = ((*ptr)->ptr)->num;
	((*ptr)->ptr)->num = temp;
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sa(list_b);
}

void	rrr(t_list **a_list, t_list **b_list)
{
	write(1, "rrr\n", 4);
	rra(a_list);
	rrb(b_list);
}
