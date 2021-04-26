#include "../includes/push_swap.h"

void
	q_sort_stack(t_stacks *st)
{
	st->grp_ctr = 0;
	q_sort_stack_first(st);
	set_sorted(st);
	while (check_stack(st) == FALSE)
	{
		if (st->b.head->exist == 0)
			q_sort_stack_a(st);
		else
			q_sort_stack_b(st);
	}
}