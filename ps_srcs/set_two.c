#include "../includes/push_swap.h"

void
	set_two(t_stacks *st)
{
	set_not_head(st);
	swap(&st->a);
	//write(1, "sa\n", 3);
	if (add_oper(st, 1) == FALSE)
		exit_error();
}
