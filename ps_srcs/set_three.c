#include "../includes/push_swap.h"

void
	w_push(t_stacks *st, char to)
{
	push(st, to);
	push(st, to);
	if (to == 'b')
		write(1, "pb\npb\n", 6);
	else
		write(1, "pa\npa\n", 6);
}

void
	set_three(t_stacks *st)
{
	set_asc_head(st);
	w_push(st, 'b');
	set_three_asc(st);
	set_three_order(st);
	w_push(st, 'a');
}