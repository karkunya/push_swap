#include "push_swap.h"
int	main(int argc, char **argv) {
//    printf("argc = %d\n\n\n", argc);
	int i = 10;
	int j = 10;
	int k = 10;

	t_list *a_list;
	t_list *prnt;
	t_list *b_list;

	b_list = NULL;
	a_list = create_list_a(argc, argv);
//	b_list = create_list_a(argc, argv);
//	i = is_list_sorted2(&a_list);
	prnt = lst_ptr(a_list);
	printf("num %d pos %d flag %d \n", (prnt)->num, prnt->pos, prnt->flag);
}
