/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:03:56 by wbeach            #+#    #+#             */
/*   Updated: 2021/10/11 19:59:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				num;
	int				pos;
	struct s_list	*ptr;
	int				flag;
}					t_list;

typedef struct s_util
{
	int		next;
	int		flag;
	int		mid;
	int		cntr;
}			t_util;

void	sa(t_list **ptr);
void	ss(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	pa(t_list **list_a, t_list **list_b);
void	ra(t_list **a_list);
int		list_len(t_list *list);
void	rb(t_list **b_list);
void	rra(t_list **a_list);
void	rrb(t_list **b_list);
void	rr(t_list **a_list, t_list **b_list);

t_list	*lst_ptr(t_list *list);
void	alg(t_list **a_list, t_list **b_list);
int		is_list_sorted(t_list **a, t_list **b);
t_list	*create_list_a(int argc, char **argv);
int		is_list_sorted2(t_list **a_list);
t_list	*lst_ptr(t_list *list);
void	an_error_was_found(t_list **a);
void	free_list(t_list **list);
void	sort_3_numbers(t_list **a);
void	sort_4_numbers(t_list **a, t_list **b);
void	sort_5_numbers(t_list **a, t_list **b);

int		ft_isdigit(int c);
void	check_char(int argc, char **argv);
int		ft_atoi(const char *str);
void	check_dup(int *list, int size, int i);
void	getpos(t_list **ptr, int *list, int size);
void	init_util(t_util *util);
int		srh_max(t_list *list);
int		is_list_sorted(t_list **a, t_list **b);
int		is_list_sorted2(t_list **a_list);
void	first_iteration(t_list **a_list, t_list **b_list, t_util *util);
t_list	*lst_ptr(t_list *list);
int		list_len(t_list *list);

#endif
