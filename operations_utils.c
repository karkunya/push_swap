/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:04:29 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 20:04:30 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_ptr(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != list->ptr)
		list = list->ptr;
	return (list);
}

int	list_len(t_list *list)
{
	t_list	*temp;
	int		i;

	if (!(list))
		return (0);
	i = 1;
	temp = list;
	while (temp != list->ptr && i++)
		list = list->ptr;
	return (i);
}
