#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				num;
	int 			pos;
	struct s_list	*ptr;
	int 			flag;
}					t_list;

typedef struct s_util
{
	int		next;
	int 	flag;
	int 	mid;
	int		cntr;
}			t_util;


void	sa(t_list **ptr);
void	pb(t_list **list_a, t_list **list_b);
void 	pa(t_list **list_a, t_list **list_b);
void    ra(t_list **a_list);
int 	list_len(t_list *list);
void    rb(t_list **b_list);
void    rra(t_list **a_list);
t_list *lst_ptr(t_list *list);
void alg(t_list **a_list, t_list **b_list);
int	is_list_sorted(t_list **a, t_list **b);
t_list	*create_list_a(int argc, char **argv);
int is_list_sorted2(t_list **a_list);
t_list *lst_ptr(t_list *list);
void	an_error_was_found(t_list **a);
void	free_list(t_list **list);

#endif