#include "../includes/push_swap.h"

void
	next_ptr_in_a(t_stacks *st, t_dlist **ptr)
{
	if (*ptr != st->a.tail)
		*ptr = (*ptr)->next;
	else
		*ptr = st->a.head;
}