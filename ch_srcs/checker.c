#include "../includes/checker.h"

__attribute__((destructor))
void    end()
{
    system("leaks checker");
}

int
	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		exit (0);
	if (check_av(ac, av) == FALSE)
		exit_error();
	st.len = ac - 1;
	if (pack_stack(&st, av) == FALSE)
		exit_error();
	if (pack_sort_array(&st) == FALSE || check_duplicate(&st) == FALSE)
		exit_error();
	if (get_do_ord(&st) == FALSE)
		exit_error();
	if (check_stack(&st) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit (0);
}
