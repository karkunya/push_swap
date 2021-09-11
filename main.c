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

void sort_int_list(int *list, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	while (i < (size - 1))
	{
		j = (size - 1);
		while (j > i)
		{
			if (list[j - 1] > list[j])
			{
				temp = list[j -1];
				list[j - 1] = list[j];
				list[j] = temp;
			}
			j--;
		}
		i++;
	}
}

int *create_list_int(int argc, char **argv)
{
    int *list;
	list = malloc(sizeof(int) * (argc - 1));
	if (!list)
		return (0);
    int i = 0;
	while (i < (argc - 1))
	{
		list[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sort_int_list(list, (argc - 1));
	return (list);
}

void getpos(t_list **ptr, int *list, int size)
{
	int i;
	t_list *temp;
	t_list *ptrl;

	ptrl = lst_ptr(*ptr);
	temp = *ptr;
	while (temp != ptrl)
	{
		i = 0;
		while (i <= size)
		{
			if (temp->num == list[i])
				temp->pos = i + 1;
			i++;
		}
		temp = temp->ptr;
	}
	i = 0;
	while (i <= size)
	{
		if (temp->num == list[i])
			temp->pos = i + 1;
		i++;
	}
}

t_list	*create_list_a(int argc, char **argv)
{
	t_list *ptr;
	t_list *ptrl;
	int     *list;
	int 	size;
	int i = argc - 1;

	list = create_list_int(argc, argv);
//	while (i--)
//	{
//		printf("num = %d pos = %d \n", list[i], i);
//	}
	printf("\n");

	size = argc - 1;
	ptrl = new_elem(ft_atoi(argv[--argc]), NULL);
	ptrl->flag = 0;
	ptr = ptrl;
	while (argc > 1) {
		ptr = new_elem(ft_atoi(argv[--argc]), ptr);
		ptr->flag = 0;
	}
	ptrl->ptr = ptr;
	getpos(&ptr, list,	size);
	free(list);
	return (ptr);
}

int	main(int argc, char **argv)
{
    printf("argc = %d\n\n\n", argc);
	int i = 10;
	int j = 10;
	int k = 10;

	t_list *a_list;
	t_list *prnt;
	t_list *b_list;

	b_list = NULL;
	a_list = create_list_a(argc, argv);
//	sa(&a_list);
//	sa(&a_list);
//	printf("ya tut");

//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
//	pb(&a_list, &b_list);
////
////	pb(&a_list, &b_list);
//
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);
//	pa(&a_list, &b_list);

////	pb(&a_list, &b_list);

//    ra(&a_list);
//    rra(&a_list);
//	printf("aaaa--------------%d-----------------\n", list_len(a_list));
//	printf("bbbb--------------%d-----------------\n", list_len(b_list));
	prnt = a_list;
	printf("tuta before\n");
	printf("a_list num = %d pos = %d \n", (prnt)->num, prnt->pos);
	prnt = prnt->ptr;
	while (prnt != a_list)
	{
		printf("a_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
		prnt = prnt->ptr;
	}
	alg(&a_list, &b_list);
	prnt = a_list;
	printf("tuta after\n");
	printf("a_list num = %d pos = %d \n", (prnt)->num, prnt->pos);
	prnt = prnt->ptr;
	while (prnt != a_list)
	{
		printf("a_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
		prnt = prnt->ptr;
	}
	prnt = b_list;
	printf("\n ");
	printf("b_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
	prnt = prnt->ptr;
	while (prnt != b_list)
	{
		printf("b_list num = %d pos = %d flag = %d \n", (prnt)->num, prnt->pos, prnt->flag);
		prnt = prnt->ptr;
	}

	printf("\n ");
	//	printf("%d", (b_list)->num);
	printf("\n ");
	return (0);
}