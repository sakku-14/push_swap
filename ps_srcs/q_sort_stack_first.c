#include "../includes/push_swap.h"

void
	q_sort_stack_first(t_stacks *st)
{
	int	pivot;
	int	counter;

	pivot = st->nums[(st->len - 1) / 2];
	counter = 0;
	while (counter < st->len)
	{
		if (st->a.head->num <= pivot)
		{
			push(st, 'b');
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(&(st->a));
			write(1, "ra\n", 3);
		}
		counter++;
	}
}
