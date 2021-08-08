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

#endif