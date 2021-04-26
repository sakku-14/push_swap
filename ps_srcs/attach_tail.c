#include "../includes/push_swap.h"

void
	attach_tail(t_stacks *st)
{
	push(st, 'a');
	rotate(&st->a);
	st->a.tail->group = -1;
}