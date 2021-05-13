#include "../includes/push_swap.h"

int
	opt_print_ans(t_stacks *st)
{
	if (optimize_ans(st) == FALSE)
		return (FALSE);
	print_ans(st);
	return (TRUE);
}
