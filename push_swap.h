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
}					t_list;


void	sa(t_list **ptr);
void	pb(t_list **list_a, t_list **list_b);
void 	pa(t_list **list_a, t_list **list_b);
void    ra(t_list **a_list);
int 	list_len(t_list *list);
void    rb(t_list **b_list);
void    rra(t_list **a_list);
t_list *lst_ptr(t_list *list);
void alg(t_list **a_list, t_list **b_list);

#endif