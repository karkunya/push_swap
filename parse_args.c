/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:03:14 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 20:02:37 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;

	temp1 = *list;
	if (!temp1)
		return ;
	temp3 = lst_ptr(*list);
	temp2 = temp1->ptr;
	while (temp3 != temp1)
	{
		free(temp1);
		temp1 = temp2;
		temp2 = temp1->ptr;
	}
}

void	an_error_was_found(t_list **a)
{
	write(1, "Error\n", 6);
	free_list(a);
	exit(1);
}
