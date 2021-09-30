#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list;
	if (!temp1)
		return ;
	temp2 = temp1->ptr;
	while (temp2)
	{
		free(temp1);
		temp1 = temp2;
		temp2 = temp1->ptr;
	}
	free(temp1);
}

void	an_error_was_found(t_list **a)
{
	write(1, "Error\n", 6);
	free_list(a);
	exit(1);
}