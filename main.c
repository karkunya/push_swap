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
	{
		count *= -1;
		i++;
	}
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

t_list	*new_elem(int num, t_list *ptr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->num = num;
	new->ptr = ptr;
	return (new);
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

void	sort_int_list(int *list, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		j = (size - 1);
		while (j > i)
		{
			if (list[j - 1] > list[j])
			{
				temp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = temp;
			}
			j--;
		}
		i++;
	}
	check_dup(list, size, 0);
}

int	*create_list_int(int argc, char **argv)
{
	int	*list;
	int	i;

	i = 0;
	list = malloc(sizeof(int) * (argc - 1));
	if (!list)
		return (0);
	while (i < (argc - 1))
	{
		list[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sort_int_list(list, (argc - 1));
	return (list);
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
			{
				temp->pos = (i + 1);
			}
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

t_list	*create_list_a(int argc, char **argv)
{
	t_list	*ptr;
	t_list	*ptrl;
	int		*list;
	int		size;

	list = create_list_int(argc, argv);
	size = argc - 1;
	ptrl = new_elem(ft_atoi(argv[--argc]), NULL);
	ptrl->flag = 0;
	ptr = ptrl;
	while (argc > 1)
	{
		ptr = new_elem(ft_atoi(argv[--argc]), ptr);
		ptr->flag = 0;
	}
	ptrl->ptr = ptr;
	getpos(&ptr, list, size);
	free(list);
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_list	*a_list;
	t_list	*b_list;

	b_list = NULL;
	a_list = create_list_a(argc, argv);
	if (is_list_sorted2(&a_list))
	{
		free_list(&a_list);
		exit(1);
	}
	if (argc == 3 && a_list->num > a_list->ptr->num)
		rra(&a_list);
	else if (argc == 4)
		sort_3_numbers(&a_list);
	else if (argc == 5)
		sort_4_numbers(&a_list, &b_list);
	else if (argc == 6)
		sort_5_numbers(&a_list, &b_list);
	else
	alg(&a_list, &b_list);
	return (0);
}
