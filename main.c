#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"


int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	count;

	result = 0;
	count = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		count *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * count);
}

t_list *new_elem(int num, t_list *ptr)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->num = num;
	new->ptr = ptr;
	return (new);
}

t_list	*create_list_a(int argc, char **argv)
{
	t_list *ptr;
	t_list *ptrl;

	ptrl = new_elem(ft_atoi(argv[argc - 1]), NULL);
	ptr = ptrl;
	while (argc-- > 1)
		ptr = new_elem(ft_atoi(argv[argc]), ptr);
	ptrl->ptr = ptr;
	return (ptr);
}


int	main(int argc, char **argv)
{
	int i = 7;
	t_list *a_list;

	a_list = create_list_a(argc, argv);
	sa(&a_list);
	while (i--)
	{
		printf("%d", (a_list)->num);
		a_list = a_list->ptr;
	}
	return (0);
}