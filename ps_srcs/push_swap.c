#include "../includes/push_swap.h"

int
	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		exit (0);
	if (check_av(ac, av) == FALSE)
		exit_error();
	if (ac > 10001)
		exit_error();
	st.len = ac - 1;
	if (pack_stack(&st, av) == FALSE)
		exit_error();
	if (pack_sort_array(&st) == FALSE || check_duplicate(&st) == FALSE)
		exit_error();
	if (check_stack(&st) == TRUE)
		exit (0);
	if (init_st_ans(&st) == FALSE)
		exit_error();
	if (st.len == 3 || st.len == 5)
		sort_less_elem(&st);
	else
		q_sort_stack(&st);
	if (opt_print_ans(&st) == FALSE)
		exit_error();
	exit (0);
}
