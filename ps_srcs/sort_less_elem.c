#include "../includes/push_swap.h"

void
	sort_less_elem(t_stacks *st)
{
	if (st->len == 3)
		sort_three(st);
	else if (st->len == 5)
		sort_five(st);
}