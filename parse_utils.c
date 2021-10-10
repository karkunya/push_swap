/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:13:36 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/10 19:13:38 by wbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_atoi(const char *str)
{
	int		i;
	size_t	result;
	int		count;

	result = 0;
	count = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		count *= -1, i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		if ((count == -1 && result > 2147483648)
			|| (count == 1 && result > 2147483647))
		{
			write(1, "Error\n", 1);
			exit(1);
		}
		i++;
	}
	return (result * count);
}

void	check_dup(int *list, int size, int i)
{
	while (i < (size - 1))
	{
		if (list[i] == list [i + 1])
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	getpos(t_list **ptr, int *list, int size)
{
	int		i;
	t_list	*temp;
	t_list	*ptrl;

	ptrl = lst_ptr(*ptr);
	temp = *ptr;
	while (temp != ptrl)
	{
		i = 0;
		while (i < size)
		{
			if (temp->num == list[i])
				temp->pos = (i + 1);
			i++;
		}
		temp = temp->ptr;
	}
	i = 0;
	while (i < size)
	{
		if (temp->num == list[i])
			temp->pos = (i + 1);
		i++;
	}
}
